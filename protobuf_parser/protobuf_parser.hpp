#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_

#include <string>

#include <protobuf_parser/protobuf_storage.hpp>
#include <protobuf_parser/view/view.hpp>

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
  // TODO: use protobuf lib to parse
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializeDirectory(const std::string& dir_path) {
  ProtobufStorage::DirectoryIterator directory_iterator{storage_.GetDirectory(/*TODO*/), &storage_};
  view::View<ProtobufStorage::DirectoryIterator, Serializer> directory_view{directory_iterator,
                                                                            serializer_};
  return directory_view.Serialize();
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializePackage(const std::string& package_name) {
  ProtobufStorage::PackageIterator package_iterator{storage_.GetPackage(/*TODO:*/), &storage_};
  view::View<ProtobufStorage::PackageIterator, Serializer> package_view{package_iterator,
                                                                        serializer_};
  return package_view.Serialize();
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
