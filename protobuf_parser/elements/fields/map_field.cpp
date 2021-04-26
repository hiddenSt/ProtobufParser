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

void MapField::Serialize(serializers::Serializer& serializer) const {
  serializer.AddField("type_name", this->GetType());
  serializer.AddField("key_type", key_type_);
  serializer.AddField("value_type", value_type_);
  serializer.AddField("name", this->GetName());
  serializer.AddField("number", std::to_string(this->GetNumber()));
  serializer.AddField("is_optional", std::to_string(this->IsOptional()));
}

}  // namespace protobuf_parser