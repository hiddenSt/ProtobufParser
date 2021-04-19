#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
class Message;

namespace builders {

class MessageBuilder {
 public:
  explicit MessageBuilder();
  ~MessageBuilder();

  const Message MessageBuildMessage(const google::protobuf::Descriptor* descriptor);
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
