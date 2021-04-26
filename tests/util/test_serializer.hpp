#ifndef PROTOBUF_PARSER_TESTS_UTIL_TEST_SERIALIZER_HPP_
#define PROTOBUF_PARSER_TESTS_UTIL_TEST_SERIALIZER_HPP_

#include <protobuf_parser/serializers/serializer.hpp>

namespace tests {
namespace util {

class TestSerializer : public protobuf_parser::serializers::Serializer {
 public:
  void AddField(const std::string& field_name, const std::string& field_value) override {
    this->field_name = field_name;
    this->field_value = field_value;
  }

  void AddArray(const std::vector<std::pair<std::string, std::string>>& entries) override {

  }

  std::string field_name;
  std::string field_value;
};

}
}


#endif  // PROTOBUF_PARSER_TESTS_UTIL_TEST_SERIALIZER_HPP_
