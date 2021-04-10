#include "json_serializer.hpp"

namespace protobuf_parser {
namespace serializer {

JsonSerializer::JsonSerializer() {
  json_representation_["messages"] = nlohmann::json::array();
}

void JsonSerializer::AddMessage(const Message& message) {
  json_representation_[message.GetName()] = {"file"};
}

std::string JsonSerializer::Serialize() {
  return json_representation_.dump();
}

}  // namespace serializer
}  // namespace protobuf_parser
