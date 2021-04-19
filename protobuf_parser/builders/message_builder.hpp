#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace builders {

class MessageBuilder {
 public:
  explicit MessageBuilder() = default;
  ~MessageBuilder() = default;

  Message BuildMessage(const google::protobuf::Descriptor* descriptor, File* file);

 private:
  void AddNestedMessages(const google::protobuf::Descriptor* descriptor);
  void AddReservedFields();
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
