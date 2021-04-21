#include "package.hpp"

namespace protobuf_parser {

const Package& Package::GetParentPackage() const noexcept {
  return *parent_package_;
}

const std::string& Package::GetName() const {
  return name_;
}

bool Package::HasParent() const noexcept {
  if (parent_package_ == nullptr) {
    return false;
  }
  return true;
}

}  // namespace protobuf_parser
