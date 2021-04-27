#include "file.hpp"

#include <algorithm>

namespace protobuf_parser {

File::File() : directory_(nullptr), package_(nullptr) {
}

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
    : Element(std::move(other)),
      path_(std::move(other.path_)),
      directory_(other.directory_),
      package_(other.package_) {
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

std::map<std::string, std::string> File::Serialize() const {
  std::map<std::string, std::string> serialized_file;
  serialized_file["id"] = std::to_string(this->GetId());
  serialized_file["path"] = path_.string();
  serialized_file["dir_id"] = std::to_string(directory_->GetId());
  if (package_ != nullptr) {
    serialized_file["package_id"] = std::to_string(package_->GetId());
  }
  return serialized_file;
}

}  // namespace protobuf_parser
