#include <gtest/gtest.h>

#include <protobuf_parser/protobuf_storage.hpp>

namespace tests {
namespace iterator {
TEST(DirectoryIteratorTests, CanIterateOverMessages) {
  protobuf_parser::ProtobufStorage storage{};
  protobuf_parser::Package a_package{"hello world"};
  protobuf_parser::Directory dir{"hello_dir"};
  protobuf_parser::File file{"name", &dir};
  protobuf_parser::Message message{"Hello world", &file, &a_package};
  storage.AddFile(file);
  storage.AddPackage(a_package);
  storage.AddDirectory(dir);
  storage.AddMessage(message);
  for (auto msg = storage.Begin(&dir); msg != storage.End<protobuf_parser::Directory>(); ++msg) {
    ASSERT_TRUE(*msg == message);
  }
}


}
}  // namespace tests