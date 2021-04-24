#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, std::size_t number, bool optional,
             bool repeated)
    : name_(name),
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

}  // namespace protobuf_parser
