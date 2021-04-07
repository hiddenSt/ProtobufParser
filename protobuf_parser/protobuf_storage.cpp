#include "protobuf_storage.hpp"

namespace protobuf_parser {

ProtobufStorage::ProtobufStorage()
    : messages_(),
      packages_(),
      files_(),
      directories_(),
      messages_count_(0),
      packages_count_(0),
      directories_count_(0),
      files_count_(0) {
}
void ProtobufStorage::AddMessage(const Message& message) {
  messages_.push_back(message);
  messages_[messages_count_].SetId(messages_count_);
  ++messages_count_;
}

void ProtobufStorage::AddPackage(const Package& package) {
  packages_.push_back(package);
  packages_[packages_count_].SetId(packages_count_);
  ++packages_count_;
}

void ProtobufStorage::AddDirectory(const Directory& directory) {
  directories_.push_back(directory);
  directories_[directories_count_].SetId(directories_count_);
  ++directories_count_;
}

void ProtobufStorage::AddFile(const File& file) {
  files_.push_back(file);
  files_[files_count_].SetId(files_count_);
  ++files_count_;
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

    for (auto& child_directory : storage_->directories_) {
      if (child_directory.GetParentDirectory() == directory) {
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