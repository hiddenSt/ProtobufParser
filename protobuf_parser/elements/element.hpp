#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_

#include <cstdint>
#include <map>
#include <string>

namespace protobuf_parser {

class Element {
 public:
  Element();
  Element(Element&& other) noexcept;

  const std::size_t GetId() const noexcept;
  virtual std::map<std::string, std::string> Serialize() const = 0;

 private:
  std::size_t id_;
  static std::size_t elements_count_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_
