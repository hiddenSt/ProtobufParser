#include "parser.hpp"

namespace protobuf_parser {

Parser::Parser(const std::filesystem::path& root_path) : root_path_(root_path) {
  // Add empty string argument as virtual_path parameter to indicate DiskSourceTree to map
  // root_path_ as a root
  // (https://developers.google.com/protocol-buffers/docs/reference/cpp/google.protobuf.compiler.importer#DiskSourceTree.MapPath.details)
  disk_source_tree_.MapPath(std::string{}, root_path_.string());
  importer_ = std::make_unique<ProtobufImporter>(&disk_source_tree_, &error_collector_);
  std::filesystem::recursive_directory_iterator recursive_directory_iterator{root_path_};

  for (auto& dir_entry : recursive_directory_iterator) {
    if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {
      std::string relative_to_root_file_path =
          GetPathRelativeToRootDirectory(dir_entry.path().string());
      auto* file_descriptor = importer_->Import(relative_to_root_file_path);
      directories_names_.insert(
          GetPathRelativeToRootDirectory(dir_entry.path().parent_path().string()));
      packages_names_.insert(file_descriptor->package());
      files_names_.insert(relative_to_root_file_path);
    }
  }
}

std::string Parser::GetPathRelativeToRootDirectory(const std::string& full_path) {
  std::string changed_path{};
  std::size_t i = 0;
  std::string root_path = root_path_.string();
  while (full_path[i] == root_path[i]) {
    ++i;
  }
  ++i;
  for (std::size_t j = i; j < full_path.size(); ++j) {
    changed_path += full_path[j];
  }
  return changed_path;
}

Storage& Parser::GetStorage() {
  return storage_;
}

void Parser::Parse() {
  AddDirectories();
  AddPackages();
  AddFiles();
  AddMessages();
  storage_ = std::move(storage_builder_.GetStorage());
}

void Parser::AddDirectories() {
  for (auto& directory_name : directories_names_) {
    builders::DirectoryBuilder builder;
    builder.SetUpPath(directory_name);
    directories_builders_.push_back(std::move(builder));
  }

  for (auto& directory_builder : directories_builders_) {
    storage_builder_.AddDirectoryBuilder(&directory_builder);
  }
}

void Parser::AddPackages() {
  for (auto& package_name : packages_names_) {
    builders::PackageBuilder builder;
    builder.SetUpName(package_name);
    packages_builders_.push_back(std::move(builder));
  }

  for (auto& package_builder : packages_builders_) {
    storage_builder_.AddPackageBuilder(&package_builder);
  }
}

void Parser::AddFiles() {
  for (auto& file_name : files_names_) {
    builders::FileBuilder builder;
    builder.SetUpPath(file_name);
    builder.SetUpPackageName(importer_->pool()->FindFileByName(file_name)->package());
    files_builders_.push_back(std::move(builder));
  }

  for (auto& file_builder : files_builders_) {
    storage_builder_.AddFileBuilder(&file_builder);
  }
}

void Parser::AddMessages() {
  const google::protobuf::DescriptorPool* pool = importer_->pool();
  for (auto& file_name : files_names_) {
    auto* file_descriptor = pool->FindFileByName(file_name);
    for (std::size_t i = 0; i < file_descriptor->message_type_count(); ++i) {
      builders::MessageBuilder builder;
      builder.SetUpName(file_descriptor->message_type(i)->name());
      builder.SetUpFileName(file_descriptor->name());
      AddNestedMessages(&builder, file_descriptor->message_type(i));
      AddMessageReservedFieldsAndNumbers(&builder, file_descriptor->message_type(i));
      AddMessageFields(&builder, file_descriptor->message_type(i));
      messages_builders_.push_back(std::move(builder));
    }
  }

  for (auto& message_builder : messages_builders_) {
    storage_builder_.AddMessageBuilder(&message_builder);
  }
}

void Parser::AddNestedMessages(builders::MessageBuilder* builder,
                               const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->nested_type_count(); ++i) {
    builders::MessageBuilder nested_builder{};
    auto nested_message_descriptor = descriptor->nested_type(i);
    nested_builder.SetUpName(nested_message_descriptor->name());
    if (nested_message_descriptor->nested_type_count() > 0) {
      AddNestedMessages(builder, nested_message_descriptor);
    }
    AddMessageFields(&nested_builder, nested_message_descriptor);
    AddMessageReservedFieldsAndNumbers(&nested_builder, nested_message_descriptor);
    builder->AddNestedMessage(std::move(nested_builder.GetMessage()));
  }
}

void Parser::AddMessageFields(builders::MessageBuilder* builder,
                              const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->field_count(); ++i) {
    auto field_descriptor = descriptor->field(i);
    builder->AddFiled(Field{field_descriptor->name(),
                            static_cast<std::size_t>(field_descriptor->number()),
                            field_descriptor->type_name(), field_descriptor->is_optional(),
                            field_descriptor->is_repeated()});
  }
}

void Parser::AddMessageReservedFieldsAndNumbers(builders::MessageBuilder* builder,
                                                const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->reserved_name_count(); ++i) {
    builder->AddReservedName(descriptor->reserved_name(i));
  }

  for (std::size_t i = 0; i < descriptor->reserved_range_count(); ++i) {
    auto range = descriptor->reserved_range(i);
    for (std::size_t reserved_number = range->start; reserved_number < range->end;
         ++reserved_number) {
      builder->AddReservedNumber(reserved_number);
    }
  }
}

}  // namespace protobuf_parser