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
  const std::string& GetName() const;

  void SetUpFilePath(const std::filesystem::path& file_path);
  const std::filesystem::path& GetFilePath();

  Message& GetMessage();

 private:
  Message message_;
  std::filesystem::path file_path_;
};

}  // namespace builders
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDER_MESSAGE_BUILDER_HPP_
