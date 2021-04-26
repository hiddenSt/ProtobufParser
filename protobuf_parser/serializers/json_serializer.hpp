#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_

#include <string>

#include <nlohmann/json.hpp>

#include <protobuf_parser/serializers/serializer.hpp>
#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace serializers {

template <typename View>
class JsonSerializer : public Serializer {
 public:
  JsonSerializer(const View& view);

  void AddField(const std::string& name, const std::string& value) override;
  void AddArray(const std::vector<std::pair<std::string, std::string>>& entries) override;
  std::string Serialize() const;

 private:
  nlohmann::json json_representation_;
  View view_;
};
template <typename View>
void JsonSerializer<View>::AddField(const std::string& name, const std::string& value) {
  json_representation_[name] = value;
}

template <typename View>
std::string JsonSerializer<View>::Serialize() const {
  for (Message& message : view_) {
    message.Serialize(this);
  }
  return json_representation_;
}

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {
}

}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
