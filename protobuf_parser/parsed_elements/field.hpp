#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_

#include <string>
#include <vector>

namespace protobuf_parser {

class Field {
 public:
  explicit Field(const std::string& name, std::size_t number, const std::string& type,
                 bool optional);
  explicit Field(std::string&& name, std::size_t number, const std::string& type,
                 bool optional) noexcept;
  Field(const Field& other) = default;

  const std::string& GetName() const;
  const std::string& GetType() const;
  std::size_t GetNumber() const;
  bool IsOptional() const noexcept;

  Field& operator=(const Field& other);

 private:
  std::string name_;
  std::string type_;
  std::size_t number_;
  bool optional_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
