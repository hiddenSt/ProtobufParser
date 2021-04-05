#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_

#include <array>
#include <string>

namespace protobuf_parser {

template <int size>
class Enum {
 public:
  explicit Enum(const std::string& name, std::array<std::string, size> nums);
  ~Enum() = default;

  std::string GetNum(size_t index);
  const std::string& GetName() const;

 private:
  std::array<std::string, size> nums_;
  std::string name_;
};

template <int size>
Enum<size>::Enum(const std::string& name, std::array<std::string, size> nums)
    : name_(name), nums_(nums) {
}

template <int size>
std::string Enum<size>::GetNum(size_t index) {
  return nums_[index];
}

template <int size>
const std::string& Enum<size>::GetName() const {
  return name_;
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ENUM_HPP_
