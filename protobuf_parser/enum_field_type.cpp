#include "enum_field_type.hpp"

namespace protobuf_parser {

const std::string& EnumFieldType::GetName() {
  return name_;
}

}  // namespace protobuf_parser