#include "field.hpp"

namespace protobuf_parser {

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
