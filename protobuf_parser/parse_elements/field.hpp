#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_

#include <string>
#include <vector>
#include <protobuf_parser/field_type.hpp>

namespace protobuf_parser {

class Field {
 public:
  explicit Field(const std::string& name, std::size_t number, FieldType* type, bool repeated);
  explicit Field(std::string&& name, std::size_t number, FieldType* type, bool repeated) noexcept;
  Field(const Field& other) = default;

  const std::string& GetName() const;
  const FieldType& GetType() const;
  std::size_t GetNumber() const;
  bool IsRepeated() const noexcept;

  Field& operator=(const Field& other);

 private:
  std::string name_;
  FieldType* type_;
  std::size_t number_;
  std::vector<Field> repeated_fields_;
  bool repeated_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
