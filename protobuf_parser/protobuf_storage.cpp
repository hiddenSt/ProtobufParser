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


ProtobufStorage::DirectoryIterator::DirectoryIterator(Directory* root_directory,
                                                      ProtobufStorage* storage)
    : storage_(storage) {
  directories_queue_.emplace(root_directory);
  for (auto& message : storage_->messages_) {
    if (*message.GetDirectory() == *root_directory && message.GetParentMessage() == nullptr) {
      current_directory_messages_.push_back(&message);
    }
  }
}

ProtobufStorage::DirectoryIterator& ProtobufStorage::DirectoryIterator::operator++() {
  Iterate();
  return *this;
}

ProtobufStorage::DirectoryIterator ProtobufStorage::DirectoryIterator::operator++(int) {
  DirectoryIterator tmp = *this;
  Iterate();
  return tmp;
}

void ProtobufStorage::DirectoryIterator::Iterate() {
  if (index_ < current_directory_messages_.size() - 1) {
    ++index_;
  } else {
    auto* directory = directories_queue_.front();
    directories_queue_.pop();

    for (auto& child_directory : storage_->directories_) {
      if (*child_directory.GetParentDirectory() == *directory) {
        directories_queue_.emplace(&child_directory);
      }
    }

    current_directory_messages_.erase(current_directory_messages_.begin(),
                                      current_directory_messages_.end());
    index_ = 0;

    for (auto& message : storage_->messages_) {
      if (*message.GetDirectory() == *directory && message.GetParentMessage() == nullptr) {
        current_directory_messages_.push_back(&message);
      }
    }
  }
}
Message& ProtobufStorage::DirectoryIterator::operator*() const {
  return *current_directory_messages_[index_];
}

ProtobufStorage::DirectoryIterator::pointer ProtobufStorage::DirectoryIterator::operator->() {
  return current_directory_messages_[index_];
}

bool operator==(const ProtobufStorage::DirectoryIterator& a,
                const ProtobufStorage::DirectoryIterator& b) {
  if (a.directories_queue_ != b.directories_queue_) {
    return false;
  }

  if (a.current_directory_messages_ != b.current_directory_messages_) {
    return false;
  }

  if (a.storage_ != b.storage_) {
    return false;
  }

  if (a.index_ != b.index_) {
    return false;
  }

  return true;
}

bool operator!=(const ProtobufStorage::DirectoryIterator& a,
                const ProtobufStorage::DirectoryIterator& b) {
  return !(a == b);
}

ProtobufStorage::PackageIterator::PackageIterator(Package* root_package, ProtobufStorage* storage)
    : storage_(storage), index_(0) {
  packages_queue_.emplace(root_package);
  for (auto& message : storage_->messages_) {
    if (*message.GetPackage() == *root_package && message.GetParentMessage() == nullptr) {
      current_package_messages_.push_back(&message);
    }
  }
}

ProtobufStorage::PackageIterator& ProtobufStorage::PackageIterator::operator++() {
  Iterate();
  return *this;
}

ProtobufStorage::PackageIterator ProtobufStorage::PackageIterator::operator++(int) {
  PackageIterator tmp = *this;
  Iterate();
  return tmp;
}

void ProtobufStorage::PackageIterator::Iterate() {
  if (index_ < current_package_messages_.size() - 1) {
    ++index_;
  } else {
    auto* package = packages_queue_.front();
    packages_queue_.pop();

    for (auto& child_package : storage_->packages_) {
      if (*child_package.GetParentPackage() == *package) {
        packages_queue_.emplace(&child_package);
      }
    }

    current_package_messages_.erase(current_package_messages_.begin(),
                                    current_package_messages_.end());
    index_ = 0;

    for (auto& message : storage_->messages_) {
      if (*message.GetPackage() == *package && message.GetParentMessage() == nullptr) {
        current_package_messages_.push_back(&message);
      }
    }
  }
}

Message& ProtobufStorage::PackageIterator::operator*() const {
  return *current_package_messages_[index_];
}

ProtobufStorage::PackageIterator::pointer ProtobufStorage::PackageIterator::operator->() {
  return current_package_messages_[index_];
}

bool operator==(const ProtobufStorage::PackageIterator& a,
                const ProtobufStorage::PackageIterator& b) {
  if (a.packages_queue_ != b.packages_queue_) {
    return false;
  }

  if (a.current_package_messages_ != b.current_package_messages_) {
    return false;
  }

  if (a.storage_ != b.storage_) {
    return false;
  }

  if (a.index_ != b.index_) {
    return false;
  }

  return true;
}

bool operator!=(const ProtobufStorage::PackageIterator& a,
                const ProtobufStorage::PackageIterator& b) {
  return !(a == b);
}

}  // namespace protobuf_parser