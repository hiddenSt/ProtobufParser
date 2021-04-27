#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_

#include <string>

#include <nlohmann/json.hpp>

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace serializers {

template <typename View>
class JsonSerializer {
 public:
  JsonSerializer(const View& view);
  std::string Serialize();

 private:
  nlohmann::json json_representation_;
  View view_;
  std::map<std::size_t, nlohmann::json> json_objects_;
};


template <typename View>
std::string JsonSerializer<View>::Serialize() {
  for (auto& message: view_) {
    for (auto& data : message.Serialize()) {
      json_objects_[message.GetId()][data.first] = data.second;
    }
    nlohmann::json fields = nlohmann::json::array();
    for (auto& field : message.GetFields()) {
     fields.push_back(field->Serialize());
    }
    json_objects_[message.GetId()]["fields"] = fields;
  }
  for (auto& object: json_objects_) {
    json_representation_.push_back(object.second);
  }
  return json_representation_.dump(4);
}

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {

}


}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
