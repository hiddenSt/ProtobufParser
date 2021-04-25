#include "enum_field.hpp"

namespace protobuf_parser {
EnumField::EnumField(const std::string& type_name, const std::string& name, std::size_t number,
                     bool optional, bool repeated)
    : Field(type_name, name, number, optional, repeated) {
}

bool EnumField::IsEnumType() const noexcept {
  return true;
}
}  // namespace protobuf_parser