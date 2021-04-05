#include "package.hpp"

namespace protobuf_parser {

Package::Package(const std::string& name) : name_(name), parent_package_(nullptr) {
}

Package::Package(const std::string& name, Package* const parent_package)
    : name_(name), parent_package_(parent_package) {
}

Package::Package(const std::string&& name) noexcept
    : name_(std::move(name)), parent_package_(nullptr) {
}

Package::Package(std::string&& name, Package* const parent_package) noexcept
    : name_(std::move(name)), parent_package_(parent_package) {
}

const Package* const Package::GetParentPackage() {
  return parent_package_;
}

const std::string& Package::GetName() const {
  return name_;
}

}  // namespace protobuf_parser
