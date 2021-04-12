#include "json_serializer.hpp"

namespace protobuf_parser {
namespace serializer {

JsonSerializer::JsonSerializer() {
}

void JsonSerializer::AddMessage(const Message& message) {
  nlohmann::json message_element;
  message_element.emplace("name", message.GetName());
  message_element.emplace("file", message.GetFile()->GetName());
  for (auto& field : message.GetFields()) {
    message_element["fields"].emplace("name", field.GetName());
    message_element["fields"].emplace("type", field.GetType());
    message_element["fields"].emplace("number", field.GetNumber());
    message_element["fields"].emplace("optional", field.IsOptional());
  }
  json_representation_["data"] = message_element;
}

std::string JsonSerializer::Serialize() {
  return json_representation_.dump();
}

}  // namespace serializer
}  // namespace protobuf_parser
