#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_

#include <string>
#include <vector>

#include <protobuf_parser/elements/element.hpp>

namespace protobuf_parser {

class Field : public Element {
 public:
  explicit Field(const std::string& name, const std::string& type_name, std::size_t number, bool optional, bool repeated);

  const std::string& GetName() const;
  const std::string& GetType() const;
  const std::size_t GetNumber() const;

  bool IsOptional() const noexcept;
  bool IsRepeated() const noexcept;
  virtual bool IsEnumType() const noexcept;
  virtual bool IsMapType() const noexcept;
  virtual bool IsBuiltinType() const noexcept;
  virtual bool IsMessageType() const noexcept;

 private:
  std::string type_name_;
  std::string name_;
  std::size_t number_;
  bool optional_;
  bool repeated_;
  bool enum_;
  bool map_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FIELD_HPP_
