#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <map>

#include <protobuf_parser/parse_elements/directory.hpp>
#include <protobuf_parser/parse_elements/message.hpp>
#include <protobuf_parser/parse_elements/package.hpp>
#include <protobuf_parser/parse_elements/file.hpp>

#include <protobuf_parser/iterator/iterator.hpp>

namespace protobuf_parser {

class ProtobufStorage {
 public:
  ProtobufStorage() = default;
  ~ProtobufStorage() = default;

  void AddMessage(const Message& message);
  void AddPackage(const Package& package);
  void AddDirectory(const Directory& directory);
  void AddFile(const File& file);

  const Message& GetMessage(std::size_t id);
  const Package& GetPackage(std::size_t id);
  const Directory& GetDirectory(std::size_t id);
  const File& GetFile(std::size_t id);

  iterator::DirectoryIterator begin();
  iterator::DirectoryIterator end();

  iterator::PackageIterator begin();
  iterator::PackageIterator end();



 private:
  std::map<std::size_t, Message> messages_;
  std::map<std::size_t, Package> packages_;
  std::map<std::size_t, Directory> directories_;
  std::map<std::size_t, File> files_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
