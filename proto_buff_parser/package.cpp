#include "package.hpp"

namespace proto_buff_parser {

Package::Package(const std::string& name): name_(name), parent_package_(nullptr) {
}


Package::Package(const std::string& name, Package* const parent_package)
    : name_(name), parent_package_(parent_package) {
}

const Package& Package::GetParentPackage() {
  return *parent_package_;
}

const std::string& Package::GetName() const {
  return name_;
}

}  // namespace proto_buff_parser
