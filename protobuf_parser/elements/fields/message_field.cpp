#include "message_field.hpp"

namespace protobuf_parser {

MessageField::MessageField(const std::string& type_name, const std::string& name,
                           std::size_t number, bool optional, bool repeated)
    : Field(type_name, name, number, optional, repeated) {
}

bool MessageField::IsMessageType() const noexcept {
  return true;
}
void MessageField::Serialize(serializers::Serializer& serializer) const {
  serializer.AddField("type_name", this->GetType());
  serializer.AddField("name", this->GetName());
  serializer.AddField("number", std::to_string(this->GetNumber()));
  serializer.AddField("is_optional", std::to_string(this->IsOptional()));
  serializer.AddField("is_repeated", std::to_string(this->IsRepeated()));
}

}  // namespace protobuf_parser
