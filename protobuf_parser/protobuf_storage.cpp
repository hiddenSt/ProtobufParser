#include "protobuf_storage.hpp"

namespace protobuf_parser {

ProtobufStorage::ProtobufStorage() : messages_(), packages_(), files_(), directories_() {
}

void ProtobufStorage::AddMessages(std::vector<Message>&& messages) {
  messages_ = std::move(messages);
}

void ProtobufStorage::AddPackages(std::vector<Package>&& packages) {
  packages_ = std::move(packages);
}

void ProtobufStorage::AddDirectories(std::vector<Directory>&& directories) {
  directories_ = std::move(directories);
}

void ProtobufStorage::AddFiles(std::vector<File>&& files) {
  files_ = std::move(files);
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