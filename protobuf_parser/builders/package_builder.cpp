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

bool PackageBuilder::IsChildOf(const std::string& package_name) {
  if (package_.name_.find(package_name + ".") == 0) {
    std::size_t i = 0;
    while (package_.name_[i] == package_name[i]) {
      ++i;
    }
    ++i;
    while (i < package_.name_.size()) {
      if (package_.name_[i] == '.') {
        return false;
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

PackageBuilder& PackageBuilder::operator=(PackageBuilder&& other) noexcept {
  package_ = std::move(other.package_);
  return *this;
}

}  // namespace builders
}  // namespace protobuf_parser
