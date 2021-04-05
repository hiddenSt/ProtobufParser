#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, std::size_t number, FieldType& type)
    : name_(name), number_(number), type_(type) {
}

Field::Field(std::string&& name, std::size_t number, FieldType& type) noexcept
    : name_(std::move(name)), number_(number), type_(type) {
}

const std::string& Field::GetName() const {
  return name_;
}

const FieldType& Field::GetType() const {
  return type_;
}

std::size_t Field::GetNumber() const {
  return number_;
}

}  // namespace protobuf_parser
