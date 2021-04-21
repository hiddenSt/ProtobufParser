#include "package.hpp"

namespace protobuf_parser {

const Package& Package::GetParentPackage() const noexcept {
  return *parent_package_;
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

bool Package::HasParent() const noexcept {
  if (parent_package_ == nullptr) {
    return false;
  }
  return true;
}

}  // namespace protobuf_parser
