#include "parser.hpp"

namespace protobuf_parser {


Parser::Parser(const std::filesystem::path& root_path)
    : root_path_(root_path) {
  // Add empty string argument as virtual_path parameter to indicate DiskSourceTree to map
  // root_path_ as a root
  // (https://developers.google.com/protocol-buffers/docs/reference/cpp/google.protobuf.compiler.importer#DiskSourceTree.MapPath.details)
  disk_source_tree_.MapPath(std::string{}, root_path_.string());
  importer_ = std::make_unique<ProtobufImporter>(&disk_source_tree_, &error_collector_);
  std::filesystem::recursive_directory_iterator recursive_directory_iterator{root_path_};

  for (auto& dir_entry : recursive_directory_iterator) {
    if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {
      std::string relative_to_root_file_path =
          GetPathRelativeToRootDirectory(dir_entry.path().string());
      auto* file_descriptor = importer_->Import(relative_to_root_file_path);
      directories_names_.insert(
          GetPathRelativeToRootDirectory(dir_entry.path().parent_path().string()));
      packages_names_.insert(file_descriptor->package());
      files_names_.insert(relative_to_root_file_path);
    }
  }
}

std::string Parser::GetPathRelativeToRootDirectory(
    const std::string& full_path) {
  std::string changed_path{};
  std::size_t i = 0;
  std::string root_path = root_path_.string();
  while (full_path[i] == root_path[i]) {
    ++i;
  }
  ++i;
  for (std::size_t j = i; j < full_path.size(); ++j) {
    changed_path += full_path[j];
  }
  return changed_path;
}

Storage Parser::GetStorage() {
  return Storage();
}

}