#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, std::size_t number, const std::string& type, bool optional,
             bool repeated)
    : name_(name),
      number_(number),
      type_(type),
      optional_(optional),
      enum_(false),
      repeated_(repeated),
      map_(false) {
}

Field::Field(std::string&& name, std::size_t number, const std::string& type, bool optional,
             bool repeated) noexcept
    : name_(std::move(name)),
      number_(number),
      type_(type),
      optional_(optional),
      enum_(false),
      repeated_(repeated),
      map_(false) {
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

bool Field::IsRepeated() const noexcept {
  return repeated_;
}

bool Field::IsEnum() const noexcept {
  return enum_;
}

bool Field::IsMap() const noexcept {
  return map_;
}
const std::vector<std::string>& Field::GetEnumValues() const {
  return enum_values_;
}

void Field::AddEnumValue(const std::string& name) {
  enum_ = true;
  enum_values_.push_back(name);
}

}  // namespace protobuf_parser
