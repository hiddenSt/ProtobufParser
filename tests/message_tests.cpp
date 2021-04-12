#include <gtest/gtest.h>

#include <protobuf_parser/parsed_elements/message.hpp>

namespace tests {

TEST(MessageTests, CanCreateMessage) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  ASSERT_EQ(message.GetName(), message_name);
}

TEST(MessageTests, CanGetNestedMessages) {
  protobuf_parser::Directory dir{"Hello world dir"};
  protobuf_parser::Package a_package{"Hello world"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};
  std::string nested_message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  protobuf_parser::Message nested_message{nested_message_name, &file, &message};
  message.AddNestedMessage(&nested_message);

  for (auto nested_message_iterator : message.GetNestedMessages()) {
    ASSERT_EQ(nested_message_iterator->GetParentMessage()->GetName(), message_name);
  }
}

TEST(MessageTests, CanGetParentMessage) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};
  std::string nested_message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  protobuf_parser::Message nested_message{nested_message_name, &file, &message};
  message.AddNestedMessage(&nested_message);

  ASSERT_TRUE(*nested_message.GetParentMessage() == message);
}

TEST(MessageTests, CanGetFile) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  ASSERT_TRUE(*message.GetFile() == file);
}

TEST(MessageTests, CanGetDirectory) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  ASSERT_TRUE(*message.GetDirectory() == dir);
}

TEST(MessageTests, CanGetPackage) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  ASSERT_TRUE(*message.GetPackage() == a_package);
}

TEST(MessageTests, CanGetMessageName) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  protobuf_parser::Message message{message_name, &file};

  ASSERT_EQ(message.GetName(), message_name);
}

TEST(MessageTests, CanGetFields) {
  protobuf_parser::Directory dir{"Hello world dit"};
  protobuf_parser::Package a_package{"HelloWorld"};
  protobuf_parser::File file{"Hello world", &dir, &a_package};
  std::string message_name{"CoolName"};

  std::string field_name{"field_name"};
  std::size_t number = 1;
  std::string type = "string";
  bool optional = false;
  bool repeated = false;
  protobuf_parser::Field field{field_name, number, type, optional, repeated};

  protobuf_parser::Message message{message_name, &file};
  message.AddField(field);

  for (auto& fields_iterator : message.GetFields()) {
    ASSERT_EQ(fields_iterator.GetName(), field_name);
    ASSERT_EQ(fields_iterator.GetNumber(), number);
    ASSERT_EQ(fields_iterator.GetType(), type);
    ASSERT_EQ(fields_iterator.IsOptional(), optional);
    ASSERT_EQ(fields_iterator.IsRepeated(), repeated);
  }
}

}  // namespace tests