#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_

#include <string>

#include <proto_buff_parser/field_type.hpp>

namespace proto_buff_parser {

class Field {
 public:
  explicit Field(const std::string& name, const std::size_t number, const FieldType& type);
  explicit Field(std::string&& name, const std::size_t number, FieldType&& type) noexcept;
  Field(const Field& other) = default;
  Field(Field&& other) noexcept;

  const std::string& GetName() const;
  const FieldType& GetType() const;
  std::size_t GetNumber() const;

 private:
  std::string name_;
  FieldType& type_;
  std::size_t number_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_HPP_
