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

}
}
