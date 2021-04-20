#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace builders {

class MessageBuilder {
 public:
  explicit MessageBuilder() = default;
  ~MessageBuilder() = default;

  void SetUpMessageName(const std::string& name) noexcept;
  void SetUpParent(Message* parent) noexcept;
  void SetUpFile(File* file) noexcept;
  void AddNestedMessage(Message&& message);
  void AddFiled(const Field& field);
  void AddReservedName(const std::string& name);
  void AddReservedNumber(std::size_t number);
  Message& GetMessage();

 private:
  Message message_;
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
