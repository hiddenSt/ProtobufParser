#include "enum_field_type.hpp"

namespace proto_buff_parser {

const std::string& EnumFieldType::GetName() {
  return name_;
}

}  // namespace proto_buff_parser