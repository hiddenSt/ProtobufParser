#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/elements/element.hpp>
#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/field.hpp>

namespace protobuf_parser {

namespace builders {
class MessageBuilder;
}

class Message : public Element {
 public:
  Message() = default;
  ~Message() = default;

  Message(Message&& other) noexcept;

  // Non-copyable
  Message(const Message&) = delete;
  Message& operator=(const Message&) = delete;

  const Package& GetPackage() const noexcept;
  const File& GetFile() const noexcept;
  const Directory& GetDirectory() const;
  const Message& GetParentMessage() const noexcept;
  const std::string& GetName() const;
  const std::vector<Field>& GetFields() const;
  const std::vector<Message>& GetNestedMessages() const;
  const std::vector<std::string>& GetReservedNames() const;
  const std::vector<std::size_t>& GetReservedNumbers() const;

 private:
  friend class builders::MessageBuilder;

  std::string name_;
  Message* parent_message_;
  File* file_;
  std::vector<Message> nested_messages_;
  std::vector<Field> fields_;
  std::vector<std::string> reserved_names_;
  std::vector<std::size_t> reserved_numbers_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
