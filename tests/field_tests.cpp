#include <gtest/gtest.h>

#include <protobuf_parser/elements/fields/builtin_field.hpp>
#include <protobuf_parser/elements/fields/message_field.hpp>
#include <protobuf_parser/elements/fields/enum_field.hpp>
#include <protobuf_parser/elements/fields/map_field.hpp>

#include <protobuf_parser/elements/package.hpp>

namespace tests {

TEST(FieldTests, CanCreateBuiltinFieldType) {
  std::string name{"field_name"};
  std::string type_name{"int64"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  ASSERT_NO_THROW(protobuf_parser::BuiltinField(type_name, name, number, optional, repeated));
}

TEST(FieldTests, CanCreateMessageFieldType) {
  std::string name{"field_name"};
  std::string type_name{"int64"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  ASSERT_NO_THROW(protobuf_parser::MessageField(type_name, name, number, optional, repeated));
}

TEST(FieldTests, CanCreateMapFieldType) {
  std::string name{"field_name"};
  std::string key_type_name{"key_type"};
  std::string value_type_name{"value_type"};
  std::size_t number = 1;
  bool optional = true;
  ASSERT_NO_THROW(
      protobuf_parser::MapField(name, number, optional, key_type_name, value_type_name));
}

TEST(FieldTests, CanCreateEnumFieldType) {
  std::string name{"field_name"};
  std::string enum_type_name{"enum_type"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  ASSERT_NO_THROW(protobuf_parser::EnumField(enum_type_name, name, number, optional, repeated));
}

TEST(FieldTests, MethodIsBuiltinOfBuiltinTypeFieldReturnsTrue) {
  std::string name{"field_name"};
  std::string type_name{"int64"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  protobuf_parser::BuiltinField field{type_name, name, number, optional, repeated};
  ASSERT_TRUE(field.IsBuiltinType());
}

TEST(FieldTests, MethodIsMessageTypeOfMessageTypeFieldReturnsTrue) {
  std::string name{"field_name"};
  std::string type_name{"int64"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  protobuf_parser::MessageField field{type_name, name, number, optional, repeated};
  ASSERT_TRUE(field.IsMessageType());
}

TEST(FieldTests, MethodIsMapOfMapFieldTypeReturnsTrue) {
  std::string name{"field_name"};
  std::string key_type_name{"key_type"};
  std::string value_type_name{"value_type"};
  std::size_t number = 1;
  bool optional = true;
  protobuf_parser::MapField field{name, number, optional, key_type_name, value_type_name};
  ASSERT_TRUE(field.IsMapType());
}

TEST(FieldTests, MethodIsRepeatedOfMapFieldTypeReturnsFalse) {
  std::string name{"field_name"};
  std::string key_type_name{"key_type"};
  std::string value_type_name{"value_type"};
  std::size_t number = 1;
  bool optional = true;
  protobuf_parser::MapField field{name, number, optional, key_type_name, value_type_name};
  ASSERT_FALSE(field.IsRepeated());
}

TEST(FieldTests, MethodIsEnumTypeOfEnumFieldTypeReturnsTrue) {
  std::string name{"field_name"};
  std::string enum_type_name{"enum_type"};
  std::size_t number = 1;
  bool optional = true;
  bool repeated = true;
  protobuf_parser::EnumField field{enum_type_name, name, number, optional, repeated};
  ASSERT_TRUE(field.IsEnumType());
}

}  // namespace tests