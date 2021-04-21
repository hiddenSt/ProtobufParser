#include <gtest/gtest.h>
#include <protobuf_parser/builders/message_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>

namespace tests {

TEST(MessageBuilderTests, CanCreateBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::MessageBuilder{});
}

TEST(MessageBuilderTests, CanSetUpName) {
  std::string name{"Hello world"};
  protobuf_parser::builders::MessageBuilder message_builder{};
  message_builder.SetUpName(name);
  auto message = std::move(message_builder.GetMessage());
  ASSERT_EQ(message.GetName(), name);
}

TEST(MessageBuilderTests, CanSetUpParent) {
  std::string parent_name{"Parent_name"};
  std::string child_name{"Child_name"};
  protobuf_parser::builders::MessageBuilder parent_builder{};
  protobuf_parser::builders::MessageBuilder child_builder{};

  parent_builder.SetUpName(parent_name);
  child_builder.SetUpName(child_name);

  auto parent = std::move(parent_builder.GetMessage());
  child_builder.SetUpParent(&parent);
  auto child = std::move(child_builder.GetMessage());

  ASSERT_EQ(&child.GetParentMessage(), &parent);
}

TEST(MessageBuilderTests, CanSetUpFile) {
  std::string message_name{"message_name"};
  std::string file_name{"file_name"};
  protobuf_parser::builders::FileBuilder file_builder{};
  file_builder.SetUpName(file_name);
  auto file = std::move(file_builder.GetFile());

  protobuf_parser::builders::MessageBuilder message_builder{};
  message_builder.SetUpName(message_name);
  message_builder.SetUpFile(&file);
  auto message = std::move(message_builder.GetMessage());

  ASSERT_EQ(&message.GetFile(), &file);
}

TEST(MessageBuilderTests, CanAddNestedMessage) {
  std::string nested_message_name{"nested_message"};
  std::string message_name{"message_name"};
  protobuf_parser::builders::MessageBuilder message_builder{};
  protobuf_parser::builders::MessageBuilder nested_message_builder{};
  nested_message_builder.SetUpName(nested_message_name);
  message_builder.SetUpName(message_name);

  auto nested_message = std::move(nested_message_builder.GetMessage());
  message_builder.AddNestedMessage(std::move(nested_message));
  auto message = std::move(message_builder.GetMessage());
  ASSERT_EQ(message.GetNestedMessages().size(), 1);
  ASSERT_EQ(message.GetNestedMessages().begin()->GetName(), nested_message_name);
}

TEST(MessageBuilderTests, NestedMessagesHasCorrectParent) {
  std::string nested_message_name{"nested_message"};
  std::string message_name{"message_name"};
  protobuf_parser::builders::MessageBuilder message_builder{};
  protobuf_parser::builders::MessageBuilder nested_message_builder{};
  nested_message_builder.SetUpName(nested_message_name);
  message_builder.SetUpName(message_name);

  auto nested_message = std::move(nested_message_builder.GetMessage());
  message_builder.AddNestedMessage(std::move(nested_message));
  auto message = std::move(message_builder.GetMessage());
  ASSERT_EQ(&message.GetNestedMessages().begin()->GetParentMessage(), &message);
}

TEST(MessageBuilderTests, CanAddField) {
}

TEST(MessageBuilderTests, CanAddReservedName) {
}

TEST(MessageBuilderTests, CanAddReservedNumber) {
}

}  // namespace tests