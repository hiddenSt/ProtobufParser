#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_IDENTIFIER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_IDENTIFIER_HPP_

#include <cstdint>
namespace protobuf_parser {

template <typename T>
class Identifier {
 public:
  Identifier() : id_(++type_elements_count_) {
  }

  std::size_t GetId() const noexcept {
    return id_;
  }

 private:
  static std::size_t type_elements_count_;
  const std::size_t id_;
};

template <typename T>
std::size_t Identifier<T>::type_elements_count_ = 0;
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_IDENTIFIER_HPP_
