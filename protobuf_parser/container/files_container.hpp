#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FILES_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FILES_CONTAINER_HPP_

#include <string>

#include <protobuf_parser/file.hpp>
#include <protobuf_parser/iterator/files_iterator.hpp>

namespace protobuf_parser {
namespace container {

class FilesContainer {
 public:
  virtual void AddFile(const File& file) = 0;
  virtual File& GetFile(const std::string& name) = 0;
  virtual iterator::FilesIterator& GetIterator() = 0;
};

}  // namespace container
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FILES_CONTAINER_HPP_
