#include "protobuf_storage.hpp"

namespace protobuf_parser {

ProtobufStorage::ProtobufStorage(std::size_t n_messages, std::size_t n_packages,
                                 std::size_t n_files, std::size_t n_directories)
    : messages_(n_messages), packages_(n_packages), files_(n_files), directories_(n_directories) {
}
void ProtobufStorage::AddMessage(const Message& message) {
  messages_[message.GetId()] = message;
}

void ProtobufStorage::AddPackage(const Package& package) {
  packages_[package.GetId()] = package;
}

void ProtobufStorage::AddDirectory(const Directory& directory) {
  directories_[directory.GetId()] = directory;
}

void ProtobufStorage::AddFile(const File& file) {
  files_[file.GetId()] = file;
}

Message* ProtobufStorage::GetMessage(std::size_t id) {
  return &messages_[id];
}

Package* ProtobufStorage::GetPackage(std::size_t id) {
  return &packages_[id];
}

Directory* ProtobufStorage::GetDirectory(std::size_t id) {
  return &directories_[id];
}

File* ProtobufStorage::GetFile(std::size_t id) {
  return &files_[id];
}

template <>
ProtobufStorage::MessagesIterator<Directory>::MessagesIterator(Directory* root,
                                                               ProtobufStorage* storage)
    : storage_(storage), index_(0) {
  queue_.emplace(root);
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

    for (auto& child_package : storage_->packages_) {
      if (*child_package.GetParentPackage() == *package) {
        queue_.emplace(&child_package);
      }
    }

    current_element_messages_.erase(current_element_messages_.begin(),
                                    current_element_messages_.end());
    index_ = 0;

    for (auto& message : storage_->messages_) {
      if (*message.GetPackage() == *package && message.GetParentMessage() == nullptr) {
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

    for (auto& child_directory : storage_->directories_) {
      if (*child_directory.GetParentDirectory() == *directory) {
        queue_.emplace(&child_directory);
      }
    }

    current_element_messages_.erase(current_element_messages_.begin(),
                                    current_element_messages_.end());
    index_ = 0;

    for (auto& message : storage_->messages_) {
      if (*message.GetDirectory() == *directory && message.GetParentMessage() == nullptr) {
        current_element_messages_.push_back(&message);
      }
    }
  }
}

}  // namespace protobuf_parser