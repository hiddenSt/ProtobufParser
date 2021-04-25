#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, const std::string& type_name_, std::size_t number,
             bool optional, bool repeated)
    : name_(name),
      type_name_(type_name_),
      number_(number),
      optional_(optional),
      enum_(false),
      repeated_(repeated),
      map_(false) {
}

const std::string& Field::GetName() const {
  return name_;
}

const std::size_t Field::GetNumber() const {
  return number_;
}

bool Field::IsOptional() const noexcept {
  return optional_;
}

bool Field::IsRepeated() const noexcept {
  return repeated_;
}

bool Field::IsEnumType() const noexcept {
  return false;
}

bool Field::IsMapType() const noexcept {
  return false;
}

bool Field::IsBuiltinType() const noexcept {
  return false;
}

bool Field::IsMessageType() const noexcept {
  return false;
}

const std::string& Field::GetType() const {
  return type_name_;
}

}  // namespace protobuf_parser
