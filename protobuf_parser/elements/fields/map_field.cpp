#include "map_field.hpp"

namespace protobuf_parser {

MapField::MapField(const std::string& name, const std::string& type_name, std::size_t number, bool optional,
                   const std::string& key_type, const std::string& value_type)
    : Field(name, type_name, number, optional, false),
      key_type_(key_type),
      value_type_(value_type) {
}

bool MapField::IsMapType() const noexcept {
  return true;
}

}