#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class MapField : public Field {
 public:
  MapField(const std::string& name, std::size_t number, bool optional, const std::string& key_type, const std::string& value_type);
  MapField() = delete;

  const std::string& GetType() const override;
  bool IsMap() const noexcept override;

 private:
  std::string key_type_;
  std::string value_type_;
  std::string type_name_;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_
