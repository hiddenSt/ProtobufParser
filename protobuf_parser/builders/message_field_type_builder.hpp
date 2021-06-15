#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_MESSAGE_FIELD_TYPE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_MESSAGE_FIELD_TYPE_BUILDER_HPP_

#include <string>

#include <protobuf_parser/elements/fields/message_field.hpp>

namespace protobuf_parser {
namespace builders {

class MessageFieldTypeBuilder {
 public:
  MessageFieldTypeBuilder(const std::string& type_name, const std::string& name,
                          std::size_t number, bool optional, bool repeated);

  void SetUpMessageTypeId(std::size_t id);

  MessageField& GetMessageField();

 private:
  MessageField message_field_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_MESSAGE_FIELD_TYPE_BUILDER_HPP_
