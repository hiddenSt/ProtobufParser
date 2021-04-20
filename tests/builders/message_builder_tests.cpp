#include <gtest/gtest.h>
#include <protobuf_parser/builders/message_builder.hpp>

namespace tests {

TEST(MessageBuilderTest, CanCreateBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::MessageBuilder{});
}

TEST(MessageBuilderTest, CanAddNameToMessage) {
  std::string name{"Hello world"};
  protobuf_parser::builders::MessageBuilder message_builder{};
  message_builder.SetUpMessageName(name);
  auto message = std::move(message_builder.GetMessage());
  ASSERT_EQ(message.GetName(), name);
}

TEST(MessageBuilderTest, CanAddParentMessageToMessage) {

}

TEST(MessageBuilderTest, CanAddFileToMesssage) {

}

TEST(MessageBuilderTest, CanGetMessageWithCorrectPointers) {

}

}