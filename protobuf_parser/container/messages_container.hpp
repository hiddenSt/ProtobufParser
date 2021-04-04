#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_

#include <string>

#include <protobuf_parser/iterator/messages_iterator.hpp>
#include <protobuf_parser/message.hpp>

namespace protobuf_parser {
namespace container {

class MessagesContainer {
 public:
  virtual void AddMessage(const Message& message) = 0;
  virtual Message& GetMessage(const std::string& name) = 0;
  virtual iterator::MessagesIterator& GetIterator() = 0;
};

}  // namespace container
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_MESSAGES_CONTAINER_HPP_
