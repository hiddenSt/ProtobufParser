#include <gtest/gtest.h>
#include <protobuf_parser/protobuf_storage.hpp>

namespace tests {
namespace iterator {

TEST(PackageIteratorTests, CanIterateOverMessages) {
  protobuf_parser::ProtobufStorage storage{};
  protobuf_parser::Package a_package{"hello world"};
  protobuf_parser::Directory dir{"hello_dir"};
  protobuf_parser::File file{"name", &dir, &a_package};
  protobuf_parser::Message message{"Hello world", &file};
  std::vector<protobuf_parser::File> files{};
  files.push_back(file);
  std::vector<protobuf_parser::Message> messages{};
  messages.push_back(message);
  std::vector<protobuf_parser::Directory> directories{};
  directories.push_back(dir);
  std::vector<protobuf_parser::Package> packages{};
  packages.push_back(a_package);
  storage.AddPackages(std::move(packages));
  storage.AddMessages(std::move(messages));
  storage.AddFiles(std::move(files));
  storage.AddDirectories(std::move(directories));

  for (auto msg = storage.Begin(&a_package); msg != storage.End<protobuf_parser::Package>(); ++msg) {
    ASSERT_TRUE(*msg == message);
  }
}
}
}  // namespace tests