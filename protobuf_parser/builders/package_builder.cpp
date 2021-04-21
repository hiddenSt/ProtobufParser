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

const std::string& PackageBuilder::GetName() const {
  return package_.GetName();
}

bool PackageBuilder::IsParent(const std::string& package_name) {
  if (package_name.find(package_.GetName() + ".") == 0) {
    std::size_t i = 0;
    while (package_.GetName()[i] == package_name[i]) {
      ++i;
    }
    ++i;
    while (i < package_name.size()) {
      if (package_name[i] == '.') {
        false;
      }
      ++i;
    }
    return true;
  }
  return false;
}

PackageBuilder::PackageBuilder(PackageBuilder&& other) noexcept
    : package_(std::move(other.package_)) {
}

}  // namespace builders
}  // namespace protobuf_parser
