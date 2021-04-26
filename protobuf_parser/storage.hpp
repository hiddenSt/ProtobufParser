#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/elements/enum.hpp>
#include <protobuf_parser/view/view.hpp>

namespace protobuf_parser {
namespace builders {
class StorageBuilder;
}

class Storage {
 public:
  Storage() = default;
  ~Storage() = default;

  Storage(Storage&& other) noexcept;
  Storage& operator=(Storage&& other) noexcept;

  // Non-copyable
  Storage(const Storage&) = delete;
  Storage& operator=(const Storage&) = delete;

  view::View<Directory> GetDirectoryView(std::filesystem::path& directory_path);
  view::View<Package> GetPackageView(std::string& package_name);

 private:
  friend class builders::StorageBuilder;
  template <typename T>
  friend class view::View;

  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
  std::vector<Enum> enums_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
