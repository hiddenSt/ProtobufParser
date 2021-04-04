#include "package.hpp"

namespace proto_buff_parser {

Package::Package(const std::string& name, Package& parent_package)
    : name_(name), parent_package_(parent_package) {
}

Package& Package::GetParentPackage() {
  return parent_package_;
}

const std::string& Package::GetName() const {
  return name_;
}

}  // namespace proto_buff_parser
