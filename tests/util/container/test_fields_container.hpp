#ifndef PROTOBUFPARSER_TESTS_UTIL_CONTAINER_TEST_FIELDS_CONTAINER_HPP_
#define PROTOBUFPARSER_TESTS_UTIL_CONTAINER_TEST_FIELDS_CONTAINER_HPP_

#include <protobuf_parser/container/fields_container.hpp>

namespace tests {
namespace container {

class TestFieldsContainer : public protobuf_parser::container::FieldsContainer {
 public:
  void AddField(const protobuf_parser::Field& field) override {
  }

  protobuf_parser::iterator::FieldsIterator& GetFieldsIterator() override {
  }
};

}  // namespace container
}  // namespace tests

#endif  // PROTOBUFPARSER_TESTS_UTIL_CONTAINER_TEST_FIELDS_CONTAINER_HPP_