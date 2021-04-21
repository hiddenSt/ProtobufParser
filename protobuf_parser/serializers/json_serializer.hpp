#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_

#include <string>

#include <nlohmann/json.hpp>

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace serializer {

template <typename View>
class JsonSerializer {
 public:
  JsonSerializer(const View& view);
  std::string Serialize();

 private:

  void AddNestedMessages(const Message& message, nlohmann::json& parent_json);
  nlohmann::json json_representation_;
  const View& view_;
};

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {
}

}  // namespace serializer
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
