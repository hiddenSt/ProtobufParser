#include "package_builder.hpp"

namespace protobuf_parser {
namespace builders {

void PackageBuilder::SetUpName(const std::string& name) noexcept {
  package_.name_ = name;
}

void PackageBuilder::SetUpParent(Package* parent) noexcept {
  package_.parent_package_ = parent;
}

Package& PackageBuilder::GetPackage() {
  return package_;
}

}
}
