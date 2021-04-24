#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class Builtin : public Field {
 public:
  explicit Builtin(const std::string& name, std::size_t number, bool optional, bool repeated, const std::string& type_name);
  Builtin() = delete;

  const std::string& GetType() const override;
  bool IsBuiltinType() const noexcept override;

 private:
  std::string type_name_;
};

}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_
