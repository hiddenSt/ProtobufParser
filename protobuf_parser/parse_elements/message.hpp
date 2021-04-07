#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/parse_element.hpp>
#include <protobuf_parser/parse_elements/file.hpp>
#include <protobuf_parser/parse_elements/package.hpp>
#include <protobuf_parser/parse_elements/field.hpp>

namespace protobuf_parser {

class Message : public ParseElement {
 public:
  Message();
  Message(const Message& other);
  explicit Message(const std::string& name, File* file, Package* package, Message* parent_message);
  explicit Message(const std::string& name, File* file, Package* package);
  ~Message() = default;

  Message& operator=(const Message& other);
  bool operator==(const Message& other);
  bool operator!=(const Message& other);

  const Package& GetPackage() const noexcept;
  const File& GetFile() const noexcept;
  const Message& GetParentMessage() const noexcept;
  const std::string& GetName() const;

 private:
  std::string name_;
  Message* parent_message_;
  File* file_;
  Package* package_;
  std::vector<Field> fields_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
