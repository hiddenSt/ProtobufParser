#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_

#include <string>

#include <nlohmann/json.hpp>

#include <protobuf_parser/parsed_elements/message.hpp>

namespace protobuf_parser {
namespace serializer {

class JsonSerializer {
 public:
  JsonSerializer();

  void AddMessage(const Message& message);
  std::string Serialize();

 private:
  void AddNestedMessages(const Message& message, nlohmann::json& parent_json);
  nlohmann::json json_representation_;
};

}  // namespace serializer
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
