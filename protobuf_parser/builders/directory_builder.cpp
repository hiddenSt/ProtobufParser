#include "directory_builder.hpp"

namespace protobuf_parser {
namespace builders {

void DirectoryBuilder::SetUpParent(Directory* parent) noexcept {
  directory_.parent_directory_ = parent;
}

void DirectoryBuilder::SetUpPath(const std::filesystem::path& path) noexcept {
  directory_.path_ = path;
}

Directory& DirectoryBuilder::GetDirectory() {
  return directory_;
}

const std::filesystem::path& DirectoryBuilder::GetPath() const {
  return directory_.GetPath();
}

bool DirectoryBuilder::IsParentOf(const std::filesystem::path directory_path) {
  return directory_path.parent_path() == directory_.path_;
}

DirectoryBuilder::DirectoryBuilder(DirectoryBuilder&& other) noexcept
    : directory_(std::move(other.directory_)) {
}

}  // namespace builders
}  // namespace protobuf_parser
