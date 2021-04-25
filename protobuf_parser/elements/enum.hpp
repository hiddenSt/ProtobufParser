#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_

#include <vector>
#include <string>
#include <map>

#include <protobuf_parser/elements/element.hpp>
#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/elements/message.hpp>

namespace protobuf_parser {
namespace builders {

class EnumBuilder;

}

class Enum : public Element {
 public:
  Enum() = default;

  bool HasParentMessage() const noexcept;
  const Message& GetParentMessage() const;
  const File& GetFile() const;
  const std::string& GetName() const;
  const std::map<std::size_t, std::string>& GetValues() const;

 private:
  friend class builders::EnumBuilder;

  std::string name_;
  std::map<std::size_t, std::string> values_;
  std::vector<std::size_t> reserved_numbers_;
  File* file_;
  Message* parent_message_;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_
