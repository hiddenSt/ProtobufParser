#include "file.hpp"

#include <algorithm>

namespace protobuf_parser {

File::File() : name_(), path_(), directory_(nullptr) {
}

protobuf_parser::File::File(const std::string& name, Directory* directory)
    : name_(name), directory_(directory), path_() {
  auto* tmp_dir = directory_;
  std::string path_element;
  while (tmp_dir != nullptr) {
    path_element = tmp_dir->GetName();
    std::reverse(path_element.begin(), path_element.end());
    path_ += "/" + path_element;
    tmp_dir = tmp_dir->GetParentDirectory();
  }

  path_ += "/";

  std::reverse(path_.begin(), path_.end());
}

const std::string& File::GetName() const noexcept {
  return name_;
}

const std::string& File::GetPath() const noexcept {
  return path_;
}

bool File::operator==(const File& other) const noexcept {
  if (name_ != other.name_) {
    return false;
  }

  if (directory_ != other.directory_) {
    return false;
  }

  return true;
}

bool File::operator!=(const File& other) const noexcept {
  return !(*this == other);
}

File& File::operator=(const File& other) {
  name_ = other.name_;
  path_ = other.path_;
  directory_ = other.directory_;
  return *this;
}

File::File(const File& other) {
  name_ = other.name_;
  path_ = other.path_;
  directory_ = other.directory_;
}

Directory* File::GetDirectory() {
  return directory_;
}

}  // namespace protobuf_parser
