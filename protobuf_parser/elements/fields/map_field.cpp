#include "map_field.hpp"

namespace protobuf_parser {

MapField::MapField(const std::string& name, std::size_t number, bool optional,
                   const std::string& key_type, const std::string& value_type)
    : Field(name, number, optional, false),
      key_type_(key_type),
      value_type_(value_type),
      type_name_("Map") {
}

const std::string& MapField::GetType() const {
  return type_name_;
}

bool MapField::IsMap() const noexcept {
  return true;
}

}