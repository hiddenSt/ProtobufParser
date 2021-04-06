#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_

#include <protobuf_parser/field_type.hpp>
#include <protobuf_parser/parse_elements/message.hpp>

namespace protobuf_parser {

class MessageFieldType : public FieldType {
 public:
  explicit MessageFieldType(const Message& message);
  ~MessageFieldType() override = default;

  const std::string& GetName() const override;

  const Message& GetMessage() const;

 private:
  const Message& message_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_FIELD_TYPE_HPP_
