#include "map_field.hpp"

namespace protobuf_parser {

MapField::MapField(const std::string& name, std::size_t number, bool optional,
                   const std::string& key_type, const std::string& value_type)
    : Field("Map", name, number, optional, false), key_type_(key_type), value_type_(value_type) {
}

bool MapField::IsMapType() const noexcept {
  return true;
}

const std::string& MapField::GetKeyTypeName() const {
  return key_type_;
}

const std::string& MapField::GetValueTypeName() const {
  return value_type_;
}

std::map<std::string, std::string> MapField::Serialize() const {
  std::map<std::string, std::string> serialized_field;
  serialized_field["name"] = name_;
  serialized_field["type_name"] = type_name_;
  serialized_field["number"] = std::to_string(number_);
  if (this->IsOptional()) {
    serialized_field["is_optional"] = "true";
  } else {
    serialized_field["is_optional"] = "false";
  }

  serialized_field["field_type"] = "Map";
  serialized_field["key_type"] = key_type_;
  serialized_field["value_type"] = value_type_;
  return serialized_field;
}

}  // namespace protobuf_parser