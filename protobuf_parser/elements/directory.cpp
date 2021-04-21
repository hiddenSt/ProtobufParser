#include "directory.hpp"

namespace protobuf_parser {

const std::string& Directory::GetName() const {
  return name_;
}

bool Directory::operator==(const Directory& other) const noexcept {
  if (name_ != other.name_) {
    return false;
  }

  if (parent_directory_ != other.parent_directory_) {
    return false;
  }

  return true;
}

bool Directory::operator!=(const Directory& other) const noexcept {
  return !(*this == other);
}

const Directory& Directory::GetParentDirectory() {
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

}  // namespace protobuf_parser
