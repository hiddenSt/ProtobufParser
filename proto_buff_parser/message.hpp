#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <proto_buff_parser/field.hpp>
#include <proto_buff_parser/file.hpp>
#include <proto_buff_parser/package.hpp>

namespace proto_buff_parser {

class Message {
 public:
  explicit Message(const std::string& name, const File& file, const Package& package, const Message& parent_message);
  explicit Message(const std::string& name, const File& file, const Package& package);

  const Package& GetPackage() const noexcept;
  const File& GetFile() const noexcept;
  const Message& GetParentMessage() const noexcept;

 private:
  std::string name_;
  Message& parent_message_;
  const File& file_;
  const Package& package_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
