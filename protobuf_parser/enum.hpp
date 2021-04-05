#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_

#include <array>
#include <string>

namespace protobuf_parser {

template <int size>
class Enum {
 public:
  explicit Enum(const std::string& name, std::array<std::string, size> values);
  ~Enum() = default;

  std::string GetValue(size_t index);
  const std::string& GetName() const;

 private:
  std::array<std::string, size> values_;
  std::string name_;
};

template <int size>
Enum<size>::Enum(const std::string& name, std::array<std::string, size> values)
    : name_(name), values_(values) {
}

template <int size>
std::string Enum<size>::GetValue(size_t index) {
  return values_[index];
}

template <int size>
const std::string& Enum<size>::GetName() const {
  return name_;
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_
