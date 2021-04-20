#include "package.hpp"

namespace protobuf_parser {

Package* Package::GetParentPackage() noexcept {
  return parent_package_;
}

const std::string& Package::GetName() const {
  return name_;
}

bool Package::operator==(const Package& other) {
  if (name_ != other.name_) {
    return false;
  }

  if (parent_package_ != other.parent_package_) {
    return false;
  }

  return true;
}

bool Package::operator!=(const Package& other) {
  return !(*this == other);
}

}  // namespace protobuf_parser
