#include <gtest/gtest.h>

#include <protobuf_parser/parse_elements/message.hpp>

namespace tests {

TEST(MessageTests, CanCreateMessage) {
  protobuf_parser::Directory dir{"Hello world dit"}
  protobuf_parser::File{"Hello world"};
  protobuf_parser::Message{};
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

}