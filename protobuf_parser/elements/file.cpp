#include "file.hpp"

#include <algorithm>

namespace protobuf_parser {

const std::string& File::GetName() const noexcept {
  return name_;
}

const std::string File::GetPath() const noexcept {
  return directory_->GetName() + "/" + name_;
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

Directory* File::GetDirectory() {
  return directory_;
}

Package* File::GetPackage() {
  return package_;
}

}  // namespace protobuf_parser
