#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_

#include <protobuf_parser/field_type.hpp>
#include <protobuf_parser/message.hpp>

namespace protobuf_parser {

class MessageFieldType : public FieldType {
 public:
  explicit MessageFieldType(const std::string name, const Message& message);

  const std::string& GetName() override;

  const Message& GetMessage() const;

 private:
  std::string name_;
  const Message& message_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_
