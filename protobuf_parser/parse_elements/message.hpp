#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/parse_element.hpp>
#include <protobuf_parser/parse_elements/file.hpp>
#include <protobuf_parser/parse_elements/package.hpp>

namespace protobuf_parser {

class Message : public ParseElement {
 public:
  Message();
  Message(const Message& other);
  explicit Message(const std::string& name, const File& file, const Package& package,
                   const Message* const parent_message);
  explicit Message(const std::string& name, const File& file, const Package& package);

  Message& operator=(const Message& other);

  ~Message() = default;

  const Package& GetPackage() const noexcept;
  const File& GetFile() const noexcept;
  const Message& GetParentMessage() const noexcept;
  const std::string& GetName() const;

 private:
  std::string name_;
  const Message* const parent_message_;
  const File& file_;
  const Package& package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_MESSAGE_HPP_
