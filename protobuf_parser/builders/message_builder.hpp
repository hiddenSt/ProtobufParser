#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_

#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace builders {

class MessageBuilder {
 public:
  MessageBuilder() = default;
  MessageBuilder(MessageBuilder&& other) noexcept;
  ~MessageBuilder() = default;

  void SetUpName(const std::string& name) noexcept;
  void SetUpParent(Message* parent) noexcept;
  void SetUpFile(File* file) noexcept;
  void AddNestedMessage(Message&& message);
  void AddFiled(const Field& field);
  void AddReservedName(const std::string& name);
  void AddReservedNumber(std::size_t number);
  void AddFile(File* file) noexcept;
  const std::string& GetName() const;

  void SetUpFileName(const std::string& file_name);
  const std::string& GetFileName();

  Message& GetMessage();

 private:
  Message message_;
  std::string file_name_;
};

}  // namespace builders
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
