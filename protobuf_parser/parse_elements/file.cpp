#include "file.hpp"

namespace protobuf_parser {

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

}  // namespace protobuf_parser
