#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_

#include <string>

#include <proto_buff_parser/package.hpp>
#include <proto_buff_parser/file.hpp>
#include <proto_buff_parser/container/messages_container.hpp>

namespace proto_buff_parser {

class Message {
 public:
  container::MessagesContainer& GetInnerMessages();
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
