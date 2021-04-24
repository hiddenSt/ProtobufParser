#include "file.hpp"

#include <algorithm>

namespace protobuf_parser {

const std::string File::GetName() const noexcept {
  return path_.filename().string();
}

const std::filesystem::path& File::GetPath() const noexcept {
  return path_;
}

const Directory& File::GetDirectory() const {
  return *directory_;
}

const Package& File::GetPackage() const {
  return *package_;
}

File::File(File&& other) noexcept
    : path_(std::move(other.path_)), directory_(other.directory_), package_(other.package_) {
  other.directory_ = nullptr;
  other.package_ = nullptr;
}

File& File::operator=(File&& other) noexcept {
  path_ = std::move(other.path_);
  directory_ = other.directory_;
  package_ = other.package_;
  other.directory_ = nullptr;
  other.package_ = nullptr;
  return *this;
}

}  // namespace protobuf_parser
