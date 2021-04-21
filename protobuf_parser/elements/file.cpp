#include "file.hpp"

#include <algorithm>

namespace protobuf_parser {

const std::string& File::GetName() const noexcept {
  return name_;
}

const std::string File::GetPath() const noexcept {
  return directory_->GetName() + "/" + name_;
}

const Directory& File::GetDirectory() const {
  return *directory_;
}

const Package& File::GetPackage() const {
  return *package_;
}

File::File(File&& other) noexcept
    : name_(std::move(other.name_)), directory_(other.directory_), package_(other.package_) {
  other.directory_ = nullptr;
  other.package_ = nullptr;
}

}  // namespace protobuf_parser
