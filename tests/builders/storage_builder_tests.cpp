#include <gtest/gtest.h>

#include <protobuf_parser/builders/storage_builder.hpp>

namespace test {

TEST(StorageBuilderTests, CanCreateBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::StorageBuilder{});
}

}
