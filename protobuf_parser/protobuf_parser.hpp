#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_

#include <string>

#include <protobuf_parser/protobuf_storage.hpp>
#include <protobuf_parser/view/view.hpp>
#include <google/protobuf/compiler/importer.h>

namespace protobuf_parser {

template <typename Serializer>
class ProtobufParser {
 public:
  ProtobufParser() = delete;
  explicit ProtobufParser(const std::string& path);

  std::string SerializeDirectory(const std::string& dir_path);
  std::string SerializePackage(const std::string& package_name);

 private:
  std::string path_;
  Serializer serializer_;
  ProtobufStorage storage_;
};

template <typename Serializer>
ProtobufParser<Serializer>::ProtobufParser(const std::string& path) : path_(path) {
  google::protobuf::compiler::Importer importer{/*TODO: add source tree*/};
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializeDirectory(const std::string& dir_path) {
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializePackage(const std::string& package_name) {
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
