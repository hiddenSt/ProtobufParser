#include "json_serializer.hpp"

protobuf_parser::serializer::JsonSerializer::JsonSerializer() {
  json_representation_["messages"] = nlohmann::json::array();
}

void protobuf_parser::serializer::JsonSerializer::AddMessage(
    const protobuf_parser::Message& message) {
  json_representation_["messages"]["name"] = message.GetName();
  json_representation_["messages"]["file"] = message.GetFile()->GetName();
  json_representation_["messages"]["package"] = message.GetPackage()->GetName();
}

std::string protobuf_parser::serializer::JsonSerializer::Serialize() {
  return json_representation_.dump();
}
