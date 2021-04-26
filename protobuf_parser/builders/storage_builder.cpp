#include "storage_builder.hpp"

namespace protobuf_parser {
namespace builders {

void StorageBuilder::AddDirectoryBuilder(DirectoryBuilder* directory_builder) {
  directory_builders_.push_back(directory_builder);
}

void StorageBuilder::AddPackageBuilder(PackageBuilder* package_builder) {
  package_builders_.push_back(package_builder);
}

void StorageBuilder::AddFileBuilder(FileBuilder* file_builder) {
  file_builders_.push_back(file_builder);
}

void StorageBuilder::AddMessageBuilder(MessageBuilder* message_builder) {
  message_builders_.push_back(message_builder);
}

void StorageBuilder::AddEnumBuilder(EnumBuilder* builder) {
  enum_builders_.push_back(builder);
}

Storage& StorageBuilder::GetStorage() {
  BuildDirectories();
  BuildPackages();
  BuildFiles();
  BuildMessages();
  BuildEnums();
  return storage_;
}

void StorageBuilder::BuildDirectories() {
  std::sort(directory_builders_.begin(), directory_builders_.end(),
            [](const DirectoryBuilder* a, const DirectoryBuilder* b) {
              return a->GetPath() < b->GetPath();
            });

  for (auto& builder : directory_builders_) {
    Directory* parent = FindParentForDirectory(builder);
    builder->SetUpParent(parent);
    storage_.directories_.emplace_back(std::move(builder->GetDirectory()));
  }
}

void StorageBuilder::BuildPackages() {
  std::sort(
      package_builders_.begin(), package_builders_.end(),
      [](const PackageBuilder* a, const PackageBuilder* b) { return a->GetName() < b->GetName(); });

  for (auto& builder : package_builders_) {
    Package* parent = FindParentForPackage(builder);
    builder->SetUpParent(parent);
    storage_.packages_.emplace_back(std::move(builder->GetPackage()));
  }
}

Package* StorageBuilder::FindParentForPackage(PackageBuilder* builder) {
  for (auto& package : storage_.packages_) {
    if (builder->IsChildOf(package.GetName())) {
      return &package;
    }
  }
  return nullptr;
}

Directory* StorageBuilder::FindParentForDirectory(DirectoryBuilder* builder) {
  for (auto& directory : storage_.directories_) {
    builder->IsParentOf(directory.GetPath());
    return &directory;
  }
  return nullptr;
}

void StorageBuilder::BuildFiles() {
  for (auto& builder : file_builders_) {
    Directory* directory = FindDirectoryForFile(builder->GetPath());
    Package* package = FindPackage(builder->GetPackageName());
    builder->SetUpDirectory(directory);
    builder->SetUpPackage(package);
    storage_.files_.emplace_back(std::move(builder->GetFile()));
  }
}

Directory* StorageBuilder::FindDirectoryForFile(const std::filesystem::path& file_path) {
  for (auto& directory : storage_.directories_) {
    if (directory.Contains(file_path)) {
      return &directory;
    }
  }
  return nullptr;
}

void StorageBuilder::BuildMessages() {
  for (auto& builder : message_builders_) {
    File* file = FindFile(builder->GetFilePath());
    builder->SetUpFile(file);
    storage_.messages_.emplace_back(std::move(builder->GetMessage()));
  }
}

void StorageBuilder::BuildEnums() {
  for (auto& builder : enum_builders_) {
    File* file = FindFile(builder->GetFilePath());
    builder->SetUpFile(file);
    storage_.enums_.emplace_back(std::move(builder->GetEnum()));
  }
}

File* StorageBuilder::FindFile(const std::filesystem::path& file_path) {
  for (auto& file : storage_.files_) {
    if (file.GetPath() == file_path) {
      return &file;
    }
  }
  return nullptr;
}

Package* StorageBuilder::FindPackage(const std::string& package_name) {
  for (auto& package : storage_.packages_) {
    if (package.GetName() == package_name) {
      return &package;
    }
  }
  return nullptr;
}

}  // namespace builders
}  // namespace protobuf_parser