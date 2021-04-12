#include <gtest/gtest.h>
#include <tests/util/mock_multiple_error_collector.hpp>

#include <filesystem>

#include <protobuf_parser/protobuf_storage.hpp>

#include <google/protobuf/compiler/importer.h>


namespace tests {

class ProtobufStorageTests : public ::testing::Test {
 protected:
  void SetUp() override {
    path_to_tests_proto_directory_ = "/home/hiddenst/internship/ProtoBuffParser/tests";
    std::filesystem::path root_path{path_to_tests_proto_directory_};
    std::filesystem::recursive_directory_iterator directory_iterator{root_path};
    disk_source_tree_ = new google::protobuf::compiler::DiskSourceTree{};
    disk_source_tree_->MapPath(std::string{}, path_to_tests_proto_directory_);
    importer_ = new google::protobuf::compiler::Importer{disk_source_tree_, mock_multiple_error_collector_};
    storage_ = new protobuf_parser::ProtobufStorage{};

    for (auto& dir_entry : directory_iterator) {
      if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {
        std::string relative_to_root_file_path =
            GetPathRelativeToRootDirectory(dir_entry.path().string(), root_path.string());
        auto* file_descriptor = importer_->Import(relative_to_root_file_path);
        directories_names.insert(
            GetPathRelativeToRootDirectory(dir_entry.path().parent_path().string(), root_path.string()));
        packages_names_.insert(file_descriptor->package());
        files_names_.insert(relative_to_root_file_path);
      }
    }
  }
  void TearDown() override {
  }

  std::string GetPathRelativeToRootDirectory(const std::string& path, const std::string& root_path) {
    std::string changed_path{};
    std::size_t i = 0;
    while (path[i] == root_path[i]) {
      ++i;
    }
    ++i;
    for (std::size_t j = i; j < path.size(); ++j) {
      changed_path += path[j];
    }
    return changed_path;
  }

  google::protobuf::compiler::Importer* importer_;
  google::protobuf::compiler::DiskSourceTree* disk_source_tree_;
  util::MockMultipleErrorCollector* mock_multiple_error_collector_;
  std::string path_to_tests_proto_directory_;
  protobuf_parser::ProtobufStorage* storage_;
  std::set<std::string> directories_names;
  std::set<std::string> packages_names_;
  std::set<std::string> files_names_;
};

TEST_F(ProtobufStorageTests, CanCreateStorage) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
}

TEST_F(ProtobufStorageTests, CanStoreDescriptorsPool) {
}

TEST_F(ProtobufStorageTests, CanFindPackage) {

}

TEST_F(ProtobufStorageTests, CanFindDirectory) {

}

TEST_F(ProtobufStorageTests, CanGetIteratorToDirectory) {

}

TEST_F(ProtobufStorageTests, CanGetIteratorToPackage) {

}

}  // namespace tests