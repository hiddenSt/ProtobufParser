#include "package.hpp"

namespace protobuf_parser {

Package::Package() : parent_package_(nullptr) {
}

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

Package::Package(Package&& other) noexcept
    : Element(std::move(other)),
      name_(std::move(other.name_)),
      parent_package_(other.parent_package_) {
  other.parent_package_ = nullptr;
}

Package& Package::operator=(Package&& other) noexcept {
  name_ = std::move(other.name_);
  parent_package_ = other.parent_package_;
  other.parent_package_ = nullptr;
  return *this;
}

std::map<std::string, std::string> Package::Serialize() const {
  std::map<std::string, std::string> serialized_package;
  serialized_package["id"] = std::to_string(this->GetId());
  serialized_package["name"] = name_;
  if (parent_package_ != nullptr) {
    serialized_package["parent_package_id"] = std::to_string(parent_package_->GetId());
  }
  return serialized_package;
}
}  // namespace protobuf_parser
