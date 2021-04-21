#include "directory.hpp"

namespace protobuf_parser {

const std::string& Directory::GetName() const {
  return name_;
}

const Directory& Directory::GetParentDirectory() const {
  return *parent_directory_;
}

bool Directory::Contains(const std::string& file_name) {
  std::size_t i = 0;
  while (file_name[i] == name_[i]) {
    ++i;
  }
  ++i;
  while (i < file_name.size()) {
    if (file_name[i] == '/') {
      return false;
    }
    ++i;
  }
  return true;
}
Directory::Directory(Directory&& directory)
    : parent_directory_(directory.parent_directory_), name_(std::move(directory.name_)) {
  directory.parent_directory_ = nullptr;
}

bool Directory::HasParent() const noexcept {
  if (parent_directory_ == nullptr) {
    return false;
  }
  return true;
}

}  // namespace protobuf_parser
