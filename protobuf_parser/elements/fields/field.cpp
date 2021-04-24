#include "field.hpp"

namespace protobuf_parser {

Field::Field(const std::string& name, std::size_t number, const std::string& type, bool optional,
             bool repeated)
    : name_(name),
      number_(number),
      optional_(optional),
      enum_(false),
      repeated_(repeated),
      map_(false) {
}

Field::Field(std::string&& name, std::size_t number, const std::string& type, bool optional,
             bool repeated) noexcept
    : name_(std::move(name)),
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

bool Field::IsEnum() const noexcept {
  return enum_;
}

bool Field::IsMap() const noexcept {
  return map_;
}


}  // namespace protobuf_parser
