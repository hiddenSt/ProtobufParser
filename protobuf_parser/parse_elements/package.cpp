#include "package.hpp"

namespace protobuf_parser {

Package::Package() : name_(), parent_package_(nullptr) {
}

Package::Package(const std::string& name) : name_(name), parent_package_(nullptr) {
}

Package::Package(const std::string& name, Package* parent_package)
    : name_(name), parent_package_(parent_package) {
}

Package::Package(std::string&& name) noexcept : name_(std::move(name)), parent_package_(nullptr) {
}

Package::Package(std::string&& name, Package* parent_package) noexcept
    : name_(std::move(name)), parent_package_(parent_package) {
}

Package* Package::GetParentPackage() {
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

void Package::SetParentPackage(Package* parent) {
  parent_package_ = parent;
}

}  // namespace protobuf_parser
