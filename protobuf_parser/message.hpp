#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/file.hpp>
#include <protobuf_parser/package.hpp>
#include <protobuf_parser/container/fields_container.hpp>

namespace protobuf_parser {

class Message {
 public:
  explicit Message(const std::string& name, const File& file, const Package& package,
                   const container::FieldsContainer& fields_container,
                   const Message& parent_message);
  explicit Message(const std::string& name, const File& file, const Package& package,
                   const container::FieldsContainer& fields_container);

  const Package& GetPackage() const noexcept;
  const File& GetFile() const noexcept;
  const Message& GetParentMessage() const noexcept;
  iterator::FieldsIterator& GetFieldsIterator();

 private:
  std::string name_;
  const Message& parent_message_;
  const container::FieldsContainer& fields_container_;
  const File& file_;
  const Package& package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
