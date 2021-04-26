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
  void AddArray(const std::string& array_field_name, const std::vector<std::pair<std::string, std::string>>& entries) override;
  std::string Serialize();

 private:
  nlohmann::json json_representation_;
  View view_;
};
template <typename View>
void JsonSerializer<View>::AddField(const std::string& name, const std::string& value) {
  json_representation_[name] = value;
}

template <typename View>
std::string JsonSerializer<View>::Serialize() {
  for (auto& message : view_) {
    message.Serialize(*this);
    for (auto& nested_message: message.GetNestedMessages()) {
      nested_message.Serialize(*this);
    }
  }
  return json_representation_.dump(4);
}

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {
}

template <typename View>
void JsonSerializer<View>::AddArray(
    const std::string& array_field_name,
    const std::vector<std::pair<std::string, std::string>>& entries) {

}

}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
