#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, std::size_t number, const std::string& type, bool optional)
    : name_(name), number_(number), type_(type), optional_(optional) {
}

Field::Field(std::string&& name, std::size_t number, const std::string& type,
             bool optional) noexcept
    : name_(std::move(name)), number_(number), type_(type), optional_(optional) {
}

const std::string& Field::GetName() const {
  return name_;
}

const std::string& Field::GetType() const {
  return type_;
}

std::size_t Field::GetNumber() const {
  return number_;
}

Field& Field::operator=(const Field& other) {
  name_ = other.name_;
  number_ = other.number_;
  type_ = other.type_;
  return *this;
}

bool Field::IsOptional() const noexcept {
  return optional_;
}

}  // namespace protobuf_parser
