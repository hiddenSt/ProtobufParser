#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class MapField : public Field {
 public:
  MapField(const std::string& name, std::size_t number, bool optional, const std::string& key_type, const std::string& value_type);
  MapField() = delete;

  bool IsMapType() const noexcept override;
  const std::string& GetKeyTypeName() const;
  const std::string& GetValueTypeName() const;

 private:
  std::string key_type_;
  std::string value_type_;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_MAP_FIELD_HPP_
