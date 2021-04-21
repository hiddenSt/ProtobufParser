#include "directory_builder.hpp"

namespace protobuf_parser {
namespace builders {

void DirectoryBuilder::SetUpParent(Directory* parent) noexcept {
  directory_.parent_directory_ = parent;
}

void DirectoryBuilder::SetUpName(const std::string& name) noexcept {
  directory_.name_ = name;
}

Directory& DirectoryBuilder::GetDirectory() {
  return directory_;
}

const std::string& DirectoryBuilder::GetName() const {
  return directory_.GetName();
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
    }
    return true;
  }
  return false;
}

}
}
