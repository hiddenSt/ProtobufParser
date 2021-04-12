#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/parsed_elements/file.hpp>
#include <protobuf_parser/parsed_elements/package.hpp>
#include <protobuf_parser/parsed_elements/field.hpp>

namespace protobuf_parser {

class Message {
 public:
  Message() = delete;
  Message(const Message& other) = default;
  explicit Message(const std::string& name, File* file, Message* parent_message);
  explicit Message(const std::string& name, File* file);
  ~Message() = default;

  bool operator==(const Message& other);
  bool operator!=(const Message& other);

  void AddField(const Field& field);
  Message* AddNestedMessage(const Message& message);
  void AddReservedName(const std::string& name);
  void AddReservedNumber(std::size_t number);
  void SetParentMessage(Message* message) noexcept;

  Package* GetPackage() const noexcept;
  File* GetFile() const noexcept;
  Directory* GetDirectory();
  Message* GetParentMessage() const noexcept;
  const std::string& GetName() const;
  const std::vector<Field>& GetFields() const;
  const std::vector<Message>& GetNestedMessages() const;
  const std::vector<std::string>& GetReservedNames() const;
  const std::vector<std::size_t>& GetReservedNumbers() const;

 private:
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
