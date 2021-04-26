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

void Package::Serialize(serializers::Serializer& serializer) const {
  serializer.AddField("name", name_);
  if (parent_package_ != nullptr) {
    serializer.AddField("parent_package_id", std::to_string(parent_package_->GetId()));
  }
}

}  // namespace protobuf_parser
