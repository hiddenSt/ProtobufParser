#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_

#include <string>

#include <proto_buff_parser/iterator/messages_iterator.hpp>
#include <proto_buff_parser/message.hpp>

namespace proto_buff_parser {
namespace container {

class MessagesContainer {
 public:
  virtual void AddMessage(const Message& message) = 0;
  virtual Message& GetMessage(const std::string& name) = 0;
  virtual iterator::MessagesIterator& GetIterator() = 0;
};

}  // namespace container
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_
