#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FILES_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FILES_CONTAINER_HPP_

#include <string>

#include <proto_buff_parser/file.hpp>
#include <proto_buff_parser/iterator/files_iterator.hpp>

namespace proto_buff_parser {
namespace container {

class FilesContainer {
 public:
  virtual void AddFile(const File& file) = 0;
  virtual File& GetFile(const std::string& name) = 0;
  virtual iterator::FilesIterator& GetIterator() = 0;
};

}  // namespace container
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FILES_CONTAINER_HPP_
