#include <gtest/gtest.h>

#include <protobuf_parser/parse_elements/message.hpp>

namespace tests {

TEST(MessageTests, CanCreateMessage) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::File file{"Hello world", &dir};
  protobuf_parser::Package a_package{"Hello world"};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file, &a_package};

  ASSERT_EQ(message.GetName(), message_name);
}

TEST(MessageTests, CanGetNestedMessages) {
}

TEST(MessageTests, CanGetParentMessage) {
}

TEST(MessageTests, CanGetFile) {
}

TEST(MessageTests, CanGetDirectory) {
}

TEST(MessageTests, CanGetMessageName) {
}

TEST(MessageTests, CanGetFields) {
}

}  // namespace tests