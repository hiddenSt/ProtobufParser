#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {
namespace builders {
class MessageFieldTypeBuilder;
}

class MessageField : public Field {
 public:
  MessageField(const std::string& type_name, const std::string& name, std::size_t number,
               bool optional, bool repeated);
  MessageField() = delete;

  bool IsMessageType() const noexcept override;

  std::map<std::string, std::string> Serialize() const override;

 private:
  friend class builders::MessageFieldTypeBuilder;

  std::size_t message_type_id_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MESSAGE_FIELD_HPP_
