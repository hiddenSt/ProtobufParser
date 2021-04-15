#include <gtest/gtest.h>
#include <tests/util/mock_multiple_error_collector.hpp>

#include <filesystem>

#include <protobuf_parser/storage.hpp>

#include <google/protobuf/compiler/importer.h>

namespace tests {

class ProtobufStorageTests : public ::testing::Test {
 protected:
  void SetUp() override {
    path_to_tests_proto_directory_ = "../../tests";
    std::filesystem::path root_path{path_to_tests_proto_directory_};
    std::filesystem::recursive_directory_iterator directory_iterator{root_path};
    disk_source_tree_ = new google::protobuf::compiler::DiskSourceTree{};
    disk_source_tree_->MapPath(std::string{}, path_to_tests_proto_directory_);
    importer_ =
        new google::protobuf::compiler::Importer{disk_source_tree_, mock_multiple_error_collector_};
    storage_ = new protobuf_parser::Storage{};

    for (auto& dir_entry : directory_iterator) {
      if (dir_entry.is_regular_file() && dir_entry.path().extension() == ".proto") {
        std::string relative_to_root_file_path =
            GetPathRelativeToRootDirectory(dir_entry.path().string(), root_path.string());
        auto* file_descriptor = importer_->Import(relative_to_root_file_path);
        directories_names.insert(GetPathRelativeToRootDirectory(
            dir_entry.path().parent_path().string(), root_path.string()));
        packages_names_.insert(file_descriptor->package());
        files_names_.insert(relative_to_root_file_path);
      }
    }
  }
  void TearDown() override {
  }

  std::string GetPathRelativeToRootDirectory(const std::string& path,
                                             const std::string& root_path) {
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
  protobuf_parser::Storage* storage_;
  std::set<std::string> directories_names;
  std::set<std::string> packages_names_;
  std::set<std::string> files_names_;
};

TEST_F(ProtobufStorageTests, CanStoreDescriptorsPool) {
  ASSERT_NO_THROW(storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                                packages_names_));
}

TEST_F(ProtobufStorageTests, CanFindPackage) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string package_1_name{"test_package"};
  std::string package_2_name{"test_package.inner_test_package"};
  auto* package_1 = storage_->FindPackage(package_1_name);
  auto* package_2 = storage_->FindPackage(package_2_name);
  ASSERT_NE(package_1, nullptr);
  ASSERT_NE(package_2, nullptr);
  ASSERT_EQ(package_1->GetName(), package_1_name);
  ASSERT_EQ(package_2->GetName(), package_2_name);
}

TEST_F(ProtobufStorageTests, ReturnsNullptrIfStorageHasNoSuchPackage) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string package_name{"NotExists"};
  auto* package = storage_->FindPackage(package_name);
  ASSERT_EQ(package, nullptr);
}

TEST_F(ProtobufStorageTests, CanFindDirectory) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string directory_name{"protos/inner_directory"};
  auto* directory = storage_->FindDirectory(directory_name);
  ASSERT_NE(directory, nullptr);
  ASSERT_EQ(directory->GetName(), directory_name);
}

TEST_F(ProtobufStorageTests, ReturnsNullptrIfStorageHasNoSuchDirectory) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string directory_name{"not/existing/directory"};
  auto* directory = storage_->FindDirectory(directory_name);
  ASSERT_EQ(directory, nullptr);
}

TEST_F(ProtobufStorageTests, CanGetIteratorToDirectory) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string directory_name{"protos/inner_directory"};
  auto* directory = storage_->FindDirectory(directory_name);
  ASSERT_NO_THROW(storage_->Begin(directory));
}

TEST_F(ProtobufStorageTests, CanIterateOverDirectories) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string directory_name{"protos"};
  auto* directory = storage_->FindDirectory(directory_name);
  std::vector<std::string> messages;
  for (auto message = storage_->Begin(directory);
       message != storage_->End<protobuf_parser::Directory>(); ++message) {
    messages.push_back(message->GetName());
  }
  ASSERT_EQ(messages.size(), 3);
}

TEST_F(ProtobufStorageTests, CanGetIteratorToPackage) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string package_name{"test_package"};
  auto* package = storage_->FindPackage(package_name);
  ASSERT_NO_THROW(storage_->Begin(package));
}

TEST_F(ProtobufStorageTests, CanIterateOverPackages) {
  storage_->StoreDescriptorPool(importer_->pool(), files_names_, directories_names,
                                packages_names_);
  std::string package_name{"test_package"};
  auto* package = storage_->FindPackage(package_name);
  std::vector<std::string> messages;
  for (auto message = storage_->Begin(package);
       message != storage_->End<protobuf_parser::Package>(); ++message) {
    messages.push_back(message->GetName());
  }
  ASSERT_EQ(messages.size(), 3);
}

}  // namespace tests