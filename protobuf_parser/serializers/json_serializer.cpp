#include "json_serializer.hpp"

namespace protobuf_parser {
namespace serializer {

JsonSerializer::JsonSerializer() {
  json_representation_ = nlohmann::json::array();
}

void JsonSerializer::AddMessage(const Message& message) {
  nlohmann::json message_element;
  message_element["name"] = message.GetName();
  message_element["file"] = message.GetFile()->GetName();
  message_element["fields"] = nlohmann::json::array();
  for (auto& field : message.GetFields()) {
    nlohmann::json field_element;
    field_element["name"] = field.GetName();
    field_element["type"] = field.GetType();
    field_element["number"] = field.GetNumber();
    field_element["optional"] = field.IsOptional();
    message_element["fields"].emplace_back(field_element);
  }
  json_representation_.emplace_back(message_element);
}

std::string JsonSerializer::Serialize() {
  return json_representation_.dump();
}

}  // namespace serializer
}  // namespace protobuf_parser
