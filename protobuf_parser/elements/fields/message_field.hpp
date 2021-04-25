#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class MessageField : public Field {
 public:
  MessageField(const std::string& type_name, const std::string& name, std::size_t number, bool optional, bool repeated);
  MessageField() = delete;

  bool IsMessageType() const noexcept override;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_
