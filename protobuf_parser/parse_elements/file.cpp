#include "file.hpp"

namespace protobuf_parser {

File::File() : name_(), path_(), directory_(nullptr) {
}

protobuf_parser::File::File(const std::string& name, const std::string& path)
    : name_(name), path_(path) {
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
