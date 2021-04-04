#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_

#include <string>

namespace proto_buff_parser {

class Field {
 public:
  explicit Field(std::string name, const std::size_t number, std::string type);
  explicit Field(std::string&& name, const std::size_t number, std::string&& type) noexcept;
  Field(const Field& other) = default;
  Field(Field&& other) noexcept;

  const std::string& GetName() const;
  const std::string& GetType() const;
  std::size_t GetNumber() const;

 private:
  std::string name_;
  std::string type_;
  std::size_t number_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_
