#include "storage.hpp"

namespace protobuf_parser {

void Storage::StoreDescriptorPool(const google::protobuf::DescriptorPool* descriptor_pool,
                                          const std::set<std::string>& files,
                                          const std::set<std::string>& directories,
                                          const std::set<std::string>& packages) {
  AddPackages(packages);
  AddDirectories(directories);
  AddFiles(descriptor_pool, files);
  AddMessagesFromFiles(descriptor_pool);
}

Directory* Storage::FindDirectory(const std::string& directory_path) {
  for (auto& directory : directories_) {
    if (directory.GetName() == directory_path) {
      return &directory;
    }
  }
  return nullptr;
}

Package* Storage::FindPackage(const std::string& package_name) {
  for (auto& package : packages_) {
    if (package_name == package.GetName()) {
      return &package;
    }
  }
  return nullptr;
}

void Storage::AddPackages(const std::set<std::string>& packages) {
  for (auto& package : packages) {
    packages_.emplace_back(package);
  }
  SetUpPackagesParents();
}

void Storage::AddDirectories(const std::set<std::string>& directories) {
  for (auto& directory : directories) {
    directories_.emplace_back(directory);
  }
  SetUpDirectoriesParents();
}

void Storage::AddFiles(const google::protobuf::DescriptorPool* descriptor_pool,
                               const std::set<std::string>& files) {
  for (auto& file : files) {
    auto* file_descriptor = descriptor_pool->FindFileByName(file);
    Package* a_package = FindPackageForFileDescriptor(file_descriptor);
    Directory* directory = FindDirectoryForFile(file);
    files_.emplace_back(file, directory, a_package);
  }
}

void Storage::AddMessagesFromFiles(
    const google::protobuf::DescriptorPool* descriptor_pool) {
  for (auto& file : files_) {
    auto* file_descriptor = descriptor_pool->FindFileByName(file.GetName());
    for (std::size_t i = 0; i < file_descriptor->message_type_count(); ++i) {
      messages_.emplace_back(Message(file_descriptor->message_type(i)->name(), &file));
      AddMessageFields(&messages_[messages_.size() - 1], file_descriptor->message_type(i));
      AddMessageReservedFieldsAndNumbers(&messages_[messages_.size() - 1],
                                         file_descriptor->message_type(i));
      AddNestedMessages(&messages_[messages_.size() - 1], file_descriptor->message_type(i));
    }
  }
}

Package* Storage::FindPackageForFileDescriptor(
    const google::protobuf::FileDescriptor* file_descriptor) {
  Package* a_package = nullptr;
  for (auto& package : packages_) {
    if (package.GetName() == file_descriptor->package()) {
      a_package = &package;
    }
  }
  return a_package;
}

Directory* Storage::FindDirectoryForFile(const std::string& file_name) {
  for (auto& dir : directories_) {
    if (dir.Contains(file_name)) {
      return &dir;
    }
  }
  return nullptr;
}

void Storage::SetUpPackagesParents() {
  // BRUTE FORCE IS VERY VERY BAD
  for (std::size_t i = 0; i < packages_.size(); ++i) {
    for (std::size_t j = 0; j < packages_.size(); ++j) {
      if (i != j) {
        if (packages_[j].GetName().find(packages_[i].GetName()) == 0) {
          packages_[j].SetParentPackage(&packages_[i]);
        }
      }
    }
  }
}

void Storage::SetUpDirectoriesParents() {
  // BRUTE FORCE IS VERY VERY BAD
  for (std::size_t i = 0; i < directories_.size(); ++i) {
    for (std::size_t j = 0; j < directories_.size(); ++j) {
      if (i != j) {
        if (directories_[j].GetName().find(directories_[i].GetName()) == 0) {
          directories_[j].SetParentDirectory(&directories_[i]);
        }
      }
    }
  }
}

void Storage::AddNestedMessages(Message* message,
                                        const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->nested_type_count(); ++i) {
    auto* nested_message =
        message->AddNestedMessage(Message(descriptor->nested_type(i)->name(), message->GetFile()));
    AddMessageFields(nested_message, descriptor->nested_type(i));
    if (descriptor->nested_type(i)->nested_type_count() > 0) {
      AddNestedMessages(nested_message, descriptor->nested_type(i));
    }
  }
}

void Storage::AddMessageFields(Message* message,
                                       const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->field_count(); ++i) {
    if (descriptor->field(i)->type_name() == std::string{"message"}) {
      message->AddField(Field(descriptor->field(i)->name(), descriptor->field(i)->number(),
                              descriptor->field(i)->message_type()->name(),
                              descriptor->field(i)->is_optional(),
                              descriptor->field(i)->is_repeated()));
    } else {
      message->AddField(Field(descriptor->field(i)->name(), descriptor->field(i)->number(),
                              descriptor->field(i)->type_name(),
                              descriptor->field(i)->is_optional(),
                              descriptor->field(i)->is_repeated()));
    }
  }
}

void Storage::AddMessageReservedFieldsAndNumbers(
    Message* message, const google::protobuf::Descriptor* descriptor) {
  for (std::size_t i = 0; i < descriptor->reserved_name_count(); ++i) {
    message->AddReservedName(descriptor->reserved_name(i));
  }

  for (std::size_t i = 0; i < descriptor->reserved_range_count(); ++i) {
    for (std::size_t number = descriptor->reserved_range(i)->start;
         number != descriptor->reserved_range(i)->end; ++number) {
      message->AddReservedNumber(number);
    }
  }
}

// ITERATORS

template <>
void Storage::MessagesIterator<Package>::EnqueueChildElements(Package* package) {
  for (auto& child_package : storage_->packages_) {
    if (child_package.GetParentPackage() != nullptr &&
        *child_package.GetParentPackage() == *package) {
      elements_queue_.push(&child_package);
    }
  }
}

template <>
void Storage::MessagesIterator<Package>::EnqueueCurrentElementMessages(Package* package) {
  for (auto& message : storage_->messages_) {
    if (message.GetPackage() == package && message.GetParentMessage() == nullptr) {
      current_element_messages_.push(&message);
    }
  }
}

template <>
void Storage::MessagesIterator<Directory>::EnqueueChildElements(Directory* directory) {
  for (auto& child_directory : storage_->directories_) {
    if (child_directory.GetParentDirectory() == directory) {
      elements_queue_.push(&child_directory);
    }
  }
}

template <>
void Storage::MessagesIterator<Directory>::EnqueueCurrentElementMessages(
    Directory* directory) {
  for (auto& message : storage_->messages_) {
    if (*message.GetDirectory() == *directory && message.GetParentMessage() == nullptr) {
      current_element_messages_.push(&message);
    }
  }
}

template <>
Storage::MessagesIterator<Directory>::MessagesIterator(Directory* root, Storage* storage)
    : storage_(storage) {
  EnqueueChildElements(root);
  EnqueueCurrentElementMessages(root);
}

template <>
Storage::MessagesIterator<Package>::MessagesIterator(Package* root, Storage* storage)
    : storage_(storage) {
  EnqueueChildElements(root);
  EnqueueCurrentElementMessages(root);
}

template <>
void Storage::MessagesIterator<Package>::Iterate() {
  if (!current_element_messages_.empty()) {
    current_element_messages_.pop();
  }
  if (current_element_messages_.empty() && !elements_queue_.empty()) {
    auto* package = elements_queue_.front();
    elements_queue_.pop();
    EnqueueChildElements(package);
    EnqueueCurrentElementMessages(package);
  }
}

template <>
void Storage::MessagesIterator<Directory>::Iterate() {
  if (!current_element_messages_.empty()) {
    current_element_messages_.pop();
  }
  if (current_element_messages_.empty() && !elements_queue_.empty()) {
    auto* directory = elements_queue_.front();
    elements_queue_.pop();
    EnqueueChildElements(directory);
    EnqueueCurrentElementMessages(directory);
  }
}

}  // namespace protobuf_parser