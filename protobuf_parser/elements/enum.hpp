#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_

#include <protobuf_parser/elements/element.hpp>
#include <vector>
#include <string>

namespace protobuf_parser {

class Enum : public Element {
 public:
  Enum() = default;
  const std::vector<std::string>& GetValues() const;
 private:
  std::vector<std::string> values_;
  std::vector<std::size_t> reserved_numbers_;
  Element* parent_;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_ENUM_HPP_
