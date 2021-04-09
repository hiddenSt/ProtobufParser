#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_

#include <string>

#include <protobuf_parser/protobuf_storage.hpp>
#include <protobuf_parser/view/view.hpp>
#include <google/protobuf/compiler/importer.h>

#include <protobuf_parser/stub_multiple_error_collector.hpp>

namespace protobuf_parser {

template <typename Serializer>
class ProtobufParser {
 public:
  ProtobufParser() = delete;
  explicit ProtobufParser(const std::string& path);

  std::string SerializeDirectory(const std::string& dir_path);
  std::string SerializePackage(const std::string& package_name);

 private:
  google::protobuf::compiler::DiskSourceTree disk_source_tree_;
  StubMultipleErrorCollector error_collector_;
  std::string path_;
  Serializer serializer_;
  ProtobufStorage storage_;
};

template <typename Serializer>
ProtobufParser<Serializer>::ProtobufParser(const std::string& path) : path_(path) {
  // Add Empty string argument as virtual_path parameter to indicate DiskSourceTree to map path_ as
  // a root
  disk_source_tree_.MapPath(std::string{}, path_);
  google::protobuf::compiler::Importer importer{&disk_source_tree_, &error_collector_};
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializeDirectory(const std::string& dir_path) {
  /*TODO: add realization*/
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializePackage(const std::string& package_name) {
  /*TODO: add realization*/
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
