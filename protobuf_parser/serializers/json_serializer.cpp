#include "json_serializer.hpp"

namespace protobuf_parser {
namespace serializer {

JsonSerializer::JsonSerializer() {
  json_representation_ = nlohmann::json::array();
}

std::string JsonSerializer::Serialize() {
  return json_representation_.dump(2);
}

void JsonSerializer::AddNestedMessages(const Message& message, nlohmann::json& parent_json) {
}

}  // namespace serializer
}  // namespace protobuf_parser
