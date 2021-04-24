#include <gtest/gtest.h>
#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

class DirectoryTests : public ::testing::Test {
 protected:
  DirectoryTests()
      : dir_path_("parent_dir_path/dir"),
        parent_dir_path_("parent_dir_path") {
  }

  void SetUp() override {
    parent_dir_builder_.SetUpPath(parent_dir_path_);
    parent_dir_ = std::move(parent_dir_builder_.GetDirectory());
    dir_builder_.SetUpPath(dir_path_);
    dir_builder_.SetUpParent(&parent_dir_);
    dir_ = std::move(dir_builder_.GetDirectory());
  }

  void TearDown() override {

  }

  std::filesystem::path dir_path_;
  std::filesystem::path parent_dir_path_;
  protobuf_parser::Directory dir_;
  protobuf_parser::Directory parent_dir_;
  protobuf_parser::builders::DirectoryBuilder dir_builder_;
  protobuf_parser::builders::DirectoryBuilder parent_dir_builder_;
};

TEST_F(DirectoryTests, CanGetPath) {
  ASSERT_NO_THROW(dir_.GetPath());
}

TEST_F(DirectoryTests, MethodGetPathReturnsCorrectPath) {
  ASSERT_EQ(dir_.GetPath(), dir_path_);
}

TEST_F(DirectoryTests, CanCallMethodHasParent) {
  ASSERT_NO_THROW(dir_.HasParent());
}

TEST_F(DirectoryTests, MethodHasParentReturnsTrueIfDirectoryHasParent) {
  ASSERT_TRUE(dir_.HasParent());
}

TEST_F(DirectoryTests, MethodHasParentReturnsFalseIfDirectoryHasNoParent) {
  ASSERT_FALSE(parent_dir_.HasParent());
}

TEST_F(DirectoryTests, MethodContainsReturnsTrueIfArgumentIsContainingFile) {
  ASSERT_TRUE(parent_dir_.Contains(dir_path_));
}

TEST_F(DirectoryTests, MethodContainsReturnsFalseIfArgumentIsNotContainingFile) {
  ASSERT_FALSE(dir_.Contains(parent_dir_path_));
}

TEST_F(DirectoryTests, CanGetParentDirectory) {
  ASSERT_NO_THROW(dir_.GetParentDirectory());
}

TEST_F(DirectoryTests, MethodGetParentDirectoryReturnsCorrectDirectory) {
  ASSERT_EQ(dir_.GetParentDirectory().GetId(), parent_dir_.GetId());
  ASSERT_EQ(dir_.GetParentDirectory().GetPath(), parent_dir_.GetPath());
}

}  // namespace tests