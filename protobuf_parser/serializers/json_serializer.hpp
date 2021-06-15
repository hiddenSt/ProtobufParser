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
  std::string SerializeEnums();

 private:
  nlohmann::ordered_json SerializeFields(const Message& message);
  nlohmann::ordered_json SerializeNestedMessages(const Message& message);
  nlohmann::ordered_json SerializeMessageReservedNames(const Message& message);
  nlohmann::ordered_json SerializeMessageReservedNumbers(const Message& message);

  nlohmann::ordered_json messages_json_representation_;
  nlohmann::ordered_json files_json_representation_;
  nlohmann::ordered_json packages_json_representation_;
  nlohmann::ordered_json directories_json_representation_;
  nlohmann::ordered_json enums_json_representation_;
  View view_;
};

template <typename View>
std::string JsonSerializer<View>::SerializeMessages() {
  auto messages_json_array = nlohmann::ordered_json::array();
  for (auto& message : view_) {
    auto message_json_object = nlohmann::ordered_json{};
    for (auto& data : message.Serialize()) {
      message_json_object[data.first] = data.second;
    }

    message_json_object["fields"] = SerializeFields(message);
    message_json_object["nested_messages"] = SerializeNestedMessages(message);
    message_json_object["reserved_names"] = SerializeMessageReservedNames(message);
    message_json_object["reserved_numbers"] = SerializeMessageReservedNumbers(message);
    messages_json_array.push_back(message_json_object);
  }
  messages_json_representation_["messages"] = messages_json_array;
  return messages_json_representation_.dump(4);
}

template <typename View>
JsonSerializer<View>::JsonSerializer(const View& view) : view_(view) {
}

template <typename View>
nlohmann::ordered_json JsonSerializer<View>::SerializeFields(const Message& message) {
  auto fields = nlohmann::ordered_json::array();
  for (auto& field : message.GetFields()) {
    fields.push_back(field->Serialize());
  }
  return fields;
}

template <typename View>
nlohmann::ordered_json JsonSerializer<View>::SerializeNestedMessages(const Message& message) {
  auto nested_messages = nlohmann::ordered_json::array();

  for (auto& nested_message : message.GetNestedMessages()) {
    nlohmann::ordered_json nested_message_object;
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
nlohmann::ordered_json JsonSerializer<View>::SerializeMessageReservedNames(const Message& message) {
  auto reserved_names_json_array = nlohmann::ordered_json::array();
  for (auto& reserved_name : message.GetReservedNames()) {
    reserved_names_json_array.push_back(reserved_name);
  }
  return reserved_names_json_array;
}

template <typename View>
nlohmann::ordered_json JsonSerializer<View>::SerializeMessageReservedNumbers(
    const Message& message) {
  auto reserved_numbers_json_array = nlohmann::ordered_json::array();
  for (auto& reserved_number : message.GetReservedNumbers()) {
    reserved_numbers_json_array.push_back(reserved_number);
  }

  return reserved_numbers_json_array;
}

template <typename View>
std::string JsonSerializer<View>::SerializeFiles() {
  auto files_json_array = nlohmann::ordered_json::array();
  for (auto& file : view_.GetFiles()) {
    auto serialized_file = file->Serialize();
    auto file_json_object = nlohmann::ordered_json{};
    for (auto& field : serialized_file) {
      file_json_object[field.first] = field.second;
    }
    files_json_array.push_back(file_json_object);
  }

  files_json_representation_["files"] = files_json_array;
  return files_json_representation_.dump(4);
}

template <typename View>
std::string JsonSerializer<View>::SerializePackages() {
  auto packages_json_array = nlohmann::ordered_json::array();
  for (auto& package : view_.GetPackages()) {
    auto serialized_package = package->Serialize();
    auto package_json_object = nlohmann::ordered_json{};
    for (auto& field : serialized_package) {
      package_json_object[field.first] = field.second;
    }
    packages_json_array.push_back(package_json_object);
  }

  packages_json_representation_["packages"] = packages_json_array;
  return packages_json_representation_.dump(4);
}

template <typename View>
std::string JsonSerializer<View>::SerializeDirectories() {
  auto directories_json_array = nlohmann::ordered_json::array();
  for (auto& directory : view_.GetDirectories()) {
    auto serialized_directory = directory->Serialize();
    auto directory_json_object = nlohmann::ordered_json{};
    for (auto& field : serialized_directory) {
      directory_json_object[field.first] = field.second;
    }
    directories_json_array.push_back(directory_json_object);
  }

  directories_json_representation_["directories"] = directories_json_array;
  return directories_json_representation_.dump(4);
}

template <typename View>
std::string JsonSerializer<View>::SerializeEnums() {
  auto enums_json_array = nlohmann::ordered_json::array();
  for (auto& view_enum : view_.GetEnums()) {
    auto serialized_enum = view_enum->Serialize();
    auto enum_json_object = nlohmann::ordered_json{};
    for (auto& field : serialized_enum) {
      enum_json_object[field.first] = field.second;
    }
    auto values_json_array = nlohmann::ordered_json::array();
    for (auto& enum_value : view_enum->GetValues()) {
      auto value_element = nlohmann::ordered_json{};
      value_element["number"] = enum_value.first;
      value_element["value_name"] = enum_value.second;
      values_json_array.push_back(value_element);
    }
    enum_json_object["values"] = values_json_array;
    enums_json_array.push_back(enum_json_object);
  }

  enums_json_representation_["enums"] = enums_json_array;
  return enums_json_representation_.dump(4);
}

}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_JSON_SERIALIZER_HPP_
