#include "directory.hpp"

namespace protobuf_parser {

const std::filesystem::path& Directory::GetPath() const {
  return path_;
}

const Directory& Directory::GetParentDirectory() const {
  return *parent_directory_;
}

bool Directory::Contains(const std::filesystem::path& file_path) const {
  return file_path.parent_path() == path_;
}
Directory::Directory(Directory&& directory)
    : Element(std::move(directory)),
      parent_directory_(directory.parent_directory_),
      path_(std::move(directory.path_)) {
  directory.parent_directory_ = nullptr;
}

bool Directory::HasParent() const noexcept {
  if (parent_directory_ == nullptr) {
    return false;
  }
  return true;
}

Directory& Directory::operator=(Directory&& other) {
  this->path_ = std::move(other.path_);
  this->parent_directory_ = other.parent_directory_;
  other.parent_directory_ = nullptr;
  return *this;
}

void Directory::Serialize(serializers::Serializer& serializer) const {
  serializer.AddField("path", path_.string());
  if (parent_directory_ != nullptr) {
    serializer.AddField("parent_dir_id", std::to_string(parent_directory_->GetId()));
  }
}

}  // namespace protobuf_parser
