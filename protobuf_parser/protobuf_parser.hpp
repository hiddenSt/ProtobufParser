#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_

#include <string>
#include <filesystem>

#include <protobuf_parser/protobuf_storage.hpp>
#include <protobuf_parser/view/view.hpp>
#include <google/protobuf/compiler/importer.h>

#include <protobuf_parser/stub_multiple_error_collector.hpp>

namespace protobuf_parser {

template <typename Serializer>
class ProtobufParser {
 public:
  ProtobufParser() = delete;
  explicit ProtobufParser(const std::string& path);

  std::string SerializeDirectory(const std::string& dir_path);
  std::string SerializePackage(const std::string& package_name);

 private:
  google::protobuf::compiler::DiskSourceTree disk_source_tree_;
  StubMultipleErrorCollector error_collector_;
  std::filesystem::path path_;
  Serializer serializer_;
  ProtobufStorage storage_;
};

template <typename Serializer>
ProtobufParser<Serializer>::ProtobufParser(const std::string& path) : path_(path) {
  // Add empty string argument as virtual_path parameter to indicate DiskSourceTree to map path_ as
  // a root
  disk_source_tree_.MapPath(std::string{}, path_.string());
  google::protobuf::compiler::Importer importer{&disk_source_tree_, &error_collector_};
  std::filesystem::recursive_directory_iterator recursive_directory_iterator{path_};

  std::vector<Message> messages;
  std::vector<Package> packages;
  std::vector<Directory> directories;
  std::vector<File> files;

  for (auto& dir_entry : recursive_directory_iterator) {
    if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {

    } else if (dir_entry.is_directory()) {
    }
  }

  storage_.AddDirectories(std::move(directories));
  storage_.AddFiles(std::move(files));
  storage_.AddPackages(std::move(packages));
  storage_.AddMessages(std::move(messages));
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializeDirectory(const std::string& dir_path) {
  auto* directory = storage_.FindDirectory(dir_path);
  view::View<Directory, Serializer> directory_view{directory, storage_, serializer_};
  return directory_view.Serialize();
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializePackage(const std::string& package_name) {
  auto* package = storage_.FindPackage(package_name);
  view::View<Package, Serializer> package_view{package, storage_, serializer_};
  return package_view.Serialize();
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
