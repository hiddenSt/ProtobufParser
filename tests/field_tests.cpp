#include <gtest/gtest.h>

#include <protobuf_parser/elements/fields/field.hpp>
#include <protobuf_parser/elements/package.hpp>

namespace tests {

TEST(FieldTests, CanGetFieldType) {
  std::string field_name{"Hello world"};
  std::string type_name{"TypeName"};
  std::size_t number = 1;

//  protobuf_parser::Field field{field_name, number, type_name, false, false};

//  ASSERT_EQ(field.GetType(), type_name);
}

TEST(FieldTests, ReturnsCorrectNumber) {
  std::string field_name{"Hello world"};
  std::string type_name{"TypeName"};
  std::size_t number = 1;

  //protobuf_parser::Field field{field_name, number, type_name, false, false};

  //ASSERT_EQ(field.GetNumber(), number);
}

TEST(FieldTests, ReturnsCorrectName) {
  std::string field_name{"Hello world"};
  std::string type_name{"TypeName"};
  std::size_t number = 1;

 // protobuf_parser::Field field{field_name, number, type_name, false, false};

  //ASSERT_EQ(field.GetName(), field_name);
}

}  // namespace tests