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

void File::Serialize(serializers::Serializer& serializer) const {
  serializer.AddField("path", path_.string());
  serializer.AddField("parent_dir_id", std::to_string(directory_->GetId()));
  if (package_ != nullptr) {
    serializer.AddField("package_id", std::to_string(package_->GetId()));
  }
}

}  // namespace protobuf_parser
