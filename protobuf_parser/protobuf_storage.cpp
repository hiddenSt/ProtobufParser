#include "protobuf_storage.hpp"

namespace protobuf_parser {

ProtobufStorage::ProtobufStorage() : messages_(), packages_(), files_(), directories_() {
}

Directory* ProtobufStorage::FindDirectory(const std::string& directory_path) {
  for (auto& directory : directories_) {
    if (directory.GetName() == directory_path) {
      return &directory;
    }
  }
  return nullptr;
}

Package* ProtobufStorage::FindPackage(const std::string& package_name) {
  for (auto& package : packages_) {
    if (package_name == package.GetName()) {
      return &package;
    }
  }
  return nullptr;
}

void ProtobufStorage::StoreDescriptorPool(const google::protobuf::DescriptorPool* descriptor_pool,
                                          const std::set<std::string>& files,
                                          const std::set<std::string>& directories,
                                          const std::set<std::string>& packages) {

  AddPackages(packages);
  AddDirectories(directories);
  AddFiles(descriptor_pool, files);
  AddMessagesFromFiles(descriptor_pool);
}

void ProtobufStorage::AddPackages(const std::set<std::string>& packages) {
  for (auto& package: packages) {
    packages_.emplace_back(package);
  }

  // BRUTE FORCE IS VERY VERY BAD
  for (std::size_t i = 0; i < packages_.size(); ++i) {
    for (std::size_t j = 0; j < packages_.size(); ++i) {
      if (i != j) {
        if (packages_[j].GetName().find(packages_[i].GetName()) == 0) {
          packages_[j].SetParentPackage(&packages_[i]);
        }
      }
    }
  }

}

void ProtobufStorage::AddDirectories(const std::set<std::string>& directories) {
  for (auto& directory: directories) {
    directories_.emplace_back(directory);
  }

  // BRUTE FORCE IS VERY VERY BAD
  for (std::size_t i = 0; i < directories_.size(); ++i) {
    for (std::size_t j = 0; j < directories_.size(); ++i) {
      if (i != j) {
        if (directories_[j].GetName().find(directories_[i].GetName()) == 0) {
          directories_[j].SetParentDirectory(&directories_[i]);
        }
      }
    }
  }
}

void ProtobufStorage::AddFiles(const google::protobuf::DescriptorPool* descriptor_pool, const std::set<std::string>& files) {
  for (auto& file: files) {
    auto* file_descriptor = descriptor_pool->FindFileByName(file);
    Package* a_package = FindFilePackage(file_descriptor);
    Directory* directory = FindFileDirectory(file_descriptor);
    files_.emplace_back(file, directory, a_package);
  }
}

void ProtobufStorage::AddMessagesFromFiles(const google::protobuf::DescriptorPool* descriptor_pool) {
  for (auto& file: files_) {
    auto* file_descriptor = descriptor_pool->FindFileByName(file.GetName());
    for (std::size_t i = 0; i < file_descriptor->message_type_count(); ++i) {
      messages_.emplace_back(Message(file_descriptor->message_type(i)->name(), &file));
      // TODO: add nested messages
    }
  }
}

Package* ProtobufStorage::FindFilePackage(const google::protobuf::FileDescriptor* file_descriptor) {
  Package* a_package = nullptr;
  for (std::size_t i = 0; i < packages_.size(); ++i) {
    if (packages_[i].GetName() == file_descriptor->package()) {
      a_package = &packages_[i];
    }
  }
}

Directory* ProtobufStorage::FindFileDirectory(
    const google::protobuf::FileDescriptor* file_descriptor) {
  Directory* directory = nullptr;
  // TODO:
  for (std::size_t i = 0; i < directories_.size(); ++i) {
    // TODO: find directory
    //if (directories_[i].GetName() == file_descriptor->) {
    //directory = &directories_[i];
    //}
  }
  return directory;
}

// ITERATORS
template <>
ProtobufStorage::MessagesIterator<Directory>::MessagesIterator(Directory* root,
                                                               ProtobufStorage* storage)
    : storage_(storage), index_(0) {
  queue_.emplace(root);
  // TODO: take out in a separate method
  for (auto& message : storage_->messages_) {
    if (*message.GetDirectory() == *root && message.GetParentMessage() == nullptr) {
      current_element_messages_.push_back(&message);
    }
  }
}

template <>
ProtobufStorage::MessagesIterator<Package>::MessagesIterator(Package* root,
                                                             ProtobufStorage* storage)
    : storage_(storage), index_(0) {
  queue_.emplace(root);
  // TODO: take out in a separate method
  for (auto& message : storage_->messages_) {
    if (*message.GetPackage() == *root && message.GetParentMessage() == nullptr) {
      current_element_messages_.push_back(&message);
    }
  }
}

template <>
void ProtobufStorage::MessagesIterator<Package>::Iterate() {
  if (index_ < current_element_messages_.size() - 1) {
    ++index_;
  } else {
    auto* package = queue_.front();
    queue_.pop();

    // TODO: take out in a separate method
    for (auto& child_package : storage_->packages_) {
      if (*child_package.GetParentPackage() == *package) {
        queue_.emplace(&child_package);
      }
    }

    current_element_messages_.erase(current_element_messages_.begin(),
                                    current_element_messages_.end());
    index_ = 0;

    // TODO: take out in a separate method
    for (auto& message : storage_->messages_) {
      if (message.GetPackage() == package && message.GetParentMessage() == nullptr) {
        current_element_messages_.push_back(&message);
      }
    }
  }
}

template <>
void ProtobufStorage::MessagesIterator<Directory>::Iterate() {
  if (index_ < current_element_messages_.size() - 1) {
    ++index_;
  } else {
    auto* directory = queue_.front();
    queue_.pop();

    // TODO: take out in a separate method
    for (auto& child_directory : storage_->directories_) {
      if (child_directory.GetParentDirectory() == directory) {
        queue_.emplace(&child_directory);
      }
    }

    current_element_messages_.erase(current_element_messages_.begin(),
                                    current_element_messages_.end());
    index_ = 0;

    // TODO: take out in a separate method
    for (auto& message : storage_->messages_) {
      if (*message.GetDirectory() == *directory && message.GetParentMessage() == nullptr) {
        current_element_messages_.push_back(&message);
      }
    }
  }
}

}  // namespace protobuf_parser