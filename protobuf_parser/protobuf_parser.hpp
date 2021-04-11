#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_

#include <string>
#include <filesystem>
#include <set>

#include <protobuf_parser/protobuf_storage.hpp>
#include <protobuf_parser/view/view.hpp>
#include <google/protobuf/compiler/importer.h>

#include <protobuf_parser/stub_multiple_error_collector.hpp>

namespace protobuf_parser {

template <typename Serializer>
class ProtobufParser {
 public:
  ProtobufParser() = delete;
  explicit ProtobufParser(const std::filesystem::path& path);

  std::string SerializeDirectory(const std::filesystem::path& dir_path);
  std::string SerializePackage(const std::string& package_name);

 private:
  std::string GetPathRelativeToRootDirectory(const std::string& full_path);
  google::protobuf::compiler::DiskSourceTree disk_source_tree_;
  StubMultipleErrorCollector error_collector_;
  std::filesystem::path path_;
  Serializer serializer_;
  ProtobufStorage storage_;
};

template <typename Serializer>
ProtobufParser<Serializer>::ProtobufParser(const std::filesystem::path& path) : path_(path) {
  // Add empty string argument as virtual_path parameter to indicate DiskSourceTree to map path_ as
  // a root
  disk_source_tree_.MapPath(std::string{}, path_.string());
  google::protobuf::compiler::Importer importer{&disk_source_tree_, &error_collector_};
  std::filesystem::recursive_directory_iterator recursive_directory_iterator{path_};

  std::set<std::string> directories_names;
  std::set<std::string> packages_names;
  std::set<std::string> files_names;

  for (auto& dir_entry : recursive_directory_iterator) {
    if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {
      std::string relative_to_root_file_path = GetPathRelativeToRootDirectory(dir_entry.path().string());
      auto* file_descriptor = importer.Import(relative_to_root_file_path);
      directories_names.insert(dir_entry.path().parent_path().string());
      packages_names.insert(file_descriptor->package());
      files_names.insert(relative_to_root_file_path);
    }
  }

  storage_.StoreDescriptorPool(importer.pool(), files_names, directories_names, packages_names);
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializeDirectory(const std::filesystem::path& dir_path) {
  auto* directory = storage_.FindDirectory(dir_path.string());
  view::View<Directory, Serializer> directory_view{directory, storage_, serializer_};
  return directory_view.Serialize();
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::SerializePackage(const std::string& package_name) {
  auto* package = storage_.FindPackage(package_name);
  view::View<Package, Serializer> package_view{package, storage_, serializer_};
  return package_view.Serialize();
}

template <typename Serializer>
std::string ProtobufParser<Serializer>::GetPathRelativeToRootDirectory(
    const std::string& full_path) {
  std::string changed_path{};
  std::size_t i = 0;
  std::string root_path = path_.string();
  while (full_path[i] == root_path[i]) {
    ++i;
  }
  ++i;
  for (std::size_t j = i; j < full_path.size(); ++j) {
    changed_path += full_path[j];
  }
  return changed_path;
}

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PROTOBUF_PARSER_HPP_
