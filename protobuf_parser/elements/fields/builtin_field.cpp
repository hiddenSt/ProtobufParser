#include "builtin_field.hpp"

namespace protobuf_parser {

BuiltinField::BuiltinField(const std::string& type_name, const std::string& name,
                           std::size_t number, bool optional, bool repeated)
    : Field(type_name, name, number, optional, repeated) {
}

bool BuiltinField::IsBuiltinType() const noexcept {
  return true;
}

std::map<std::string, std::string> BuiltinField::Serialize() const {
  std::map<std::string, std::string> serialized_field;
  serialized_field["name"] = name_;
  serialized_field["type_name"] = type_name_;
  serialized_field["number"] = std::to_string(number_);
  if (this->IsOptional()) {
    serialized_field["is_optional"] = "true";
  } else {
    serialized_field["is_optional"] = "false";
  }

  if (this->IsRepeated()) {
    serialized_field["is_repeated"] = "true";
  } else {
    serialized_field["is_repeated"] = "false";
  }

  serialized_field["field_type"] = "Builtin";
  return serialized_field;
}

}  // namespace protobuf_parser