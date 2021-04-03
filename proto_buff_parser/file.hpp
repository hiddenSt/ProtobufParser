#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_

#include <string>

#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/package.hpp>

namespace proto_buff_parser {

class File {
 public:
  Package& GetPackage();
  std::string GetName() const noexcept;
  std::string GetPath() const noexcept;
  container::MessagesContainer& GetMessages() const noexcept;

 private:
  std::string name_;
  std::string path_;
  Package& package_;
  container::MessagesContainer& messages_container_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_
