#include "directory.hpp"

namespace protobuf_parser {

Directory::Directory(const std::string& name) : name_(name), parent_directory_(nullptr) {
}

Directory::Directory(const std::string& name, protobuf_parser::Directory* parent_directory)
    : name_(name), parent_directory_(parent_directory) {
}

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

}  // namespace protobuf_parser