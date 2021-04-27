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
  std::string SerializeMessages();

  std::string SerializeFiles();
  std::string SerializePackages();
  std::string SerializeDirectories();

 private:
  nlohmann::json SerializeFields(const Message& message);
  nlohmann::json SerializeNestedMessages(const Message& message);

  nlohmann::json messages_json_representation_;
  nlohmann::json files_json_representation_;
  nlohmann::json packages_json_representation_;
  View view_;
  std::map<std::size_t, nlohmann::json> messages_json_objects_;
  std::map<std::size_t, nlohmann::json> files_json_objects_;
  std::map<std::size_t, nlohmann::json> packages_json_objects_;

};

template <typename View>
std::string JsonSerializer<View>::SerializeMessages() {
  for (auto& message : view_) {
    for (auto& data : message.Serialize()) {
      messages_json_objects_[message.GetId()][data.first] = data.second;
    }

    messages_json_objects_[message.GetId()]["fields"] = SerializeFields(message);
    messages_json_objects_[message.GetId()]["nested_messages"] = SerializeNestedMessages(message);
  }
  for (auto& object : messages_json_objects_) {
    messages_json_representation_.push_back(object.second);
  }
  return messages_json_representation_.dump(4);
}

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {
}
template <typename View>
nlohmann::json JsonSerializer<View>::SerializeFields(const Message& message) {
  nlohmann::json fields = nlohmann::json::array();
  for (auto& field : message.GetFields()) {
    fields.push_back(field->Serialize());
  }
  return fields;
}

template <typename View>
nlohmann::json JsonSerializer<View>::SerializeNestedMessages(const Message& message) {
  nlohmann::json nested_messages = nlohmann::json::array();

  for (auto& nested_message : message.GetNestedMessages()) {
    nlohmann::json nested_message_object;
    for (auto& data : nested_message.Serialize()) {
      nested_message_object[data.first] = data.second;
    }

    nested_message_object["fields"] = SerializeFields(nested_message);
    nested_message_object["nested_messages"] = SerializeNestedMessages(nested_message);
    nested_messages.push_back(nested_message_object);
  }
  return nested_messages;
}

template <typename View>
std::string JsonSerializer<View>::SerializeFiles() {
  for (auto& message: view_) {
    auto serialized_data = message.GetFile().Serialize();
    for (auto& field: serialized_data) {
      files_json_objects_[message.GetFile().GetId()][field.first] = field.second;
    }
  }
  for (auto& object : files_json_objects_) {
    files_json_representation_.push_back(object.second);
  }
  return files_json_representation_.dump(4);
}

template <typename View>
std::string JsonSerializer<View>::SerializePackages() {
  for (auto& message: view_) {
    auto serialized_data = message.GetFile().GetPackage().Serialize();
    for (auto& field: serialized_data) {
      packages_json_objects_[message.GetFile().GetPackage().GetId()][field.first] = field.second;
    }
  }
  for (auto& object : packages_json_objects_) {
    packages_json_representation_.push_back(object.second);
  }
  return packages_json_representation_.dump(4);
}

}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
