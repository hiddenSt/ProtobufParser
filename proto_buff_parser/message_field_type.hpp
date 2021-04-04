#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_FIELD_TYPE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_FIELD_TYPE_HPP_

#include <proto_buff_parser/field_type.hpp>
#include <proto_buff_parser/message.hpp>

namespace proto_buff_parser {

class MessageFieldType : public FieldType {
 public:
  explicit MessageFieldType(const std::string name, const Message& message);

  const std::string& GetName() override;

  const Message& GetMessage() const;

 private:
  std::string name_;
  const Message& message_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_FIELD_TYPE_HPP_
