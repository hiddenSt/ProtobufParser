#include <gtest/gtest.h>
#include <protobuf_parser/protobuf_storage.hpp>

namespace tests {

TEST(ProtobufStorageTests, CanCreateStorage) {
  protobuf_parser::ProtobufStorage{10, 20, 30, 40};
}

}