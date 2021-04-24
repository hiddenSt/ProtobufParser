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

bool DirectoryBuilder::IsParent(const std::string& directory_name) {
  if (directory_name.find(directory_.GetName() + "/") == 0) {
    std::size_t i = 0;
    while (directory_.GetName()[i] == directory_name[i]) {
      ++i;
    }
    ++i;
    while (i < directory_name.size()) {
      if (directory_name[i] == '/') {
        return false;
      }
      ++i;
    }
    return true;
  }
  return false;
}

DirectoryBuilder::DirectoryBuilder(DirectoryBuilder&& other) noexcept
    : directory_(std::move(other.directory_)) {
}

}  // namespace builders
}  // namespace protobuf_parser
