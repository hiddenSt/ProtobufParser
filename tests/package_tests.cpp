#include <gtest/gtest.h>

#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

class PackageTests : public ::testing::Test {
 protected:
  PackageTests()
      : package_name_("parent_package.child_package"),
        parent_package_name_("parent_package") {}

  void SetUp() override {
    parent_package_builder_.SetUpName(parent_package_name_);
    package_builder_.SetUpName(package_name_);
    parent_package_ = std::move(parent_package_builder_.GetPackage());
    package_builder_.SetUpParent(&parent_package_);
    package_ = std::move(package_builder_.GetPackage());
  }

  void TearDown() override {

  }
  std::string package_name_;
  std::string parent_package_name_;
  protobuf_parser::builders::PackageBuilder package_builder_;
  protobuf_parser::builders::PackageBuilder parent_package_builder_;
  protobuf_parser::Package parent_package_;
  protobuf_parser::Package package_;
};

TEST_F(PackageTests, CanGetPackageName) {
  ASSERT_NO_THROW(package_.GetName());
}

TEST_F(PackageTests, MethodGetPackageNameReturnsCorrectName) {
  ASSERT_EQ(package_.GetName(), package_name_);
}

TEST_F(PackageTests, CanGetParentPackage) {
  ASSERT_NO_THROW(package_.GetParentPackage());
}

TEST_F(PackageTests, MethodGetParentPackageReturnsCorrectPackage) {
  ASSERT_EQ(package_.GetParentPackage().GetId(), parent_package_.GetId());
  ASSERT_EQ(package_.GetParentPackage().GetName(), parent_package_name_);
}

TEST_F(PackageTests, CanCallMethodHasParent) {
  ASSERT_NO_THROW(package_.HasParent());
}

TEST_F(PackageTests, MethodHasParentReturnsTrueIfPackageHasParent) {
  ASSERT_TRUE(package_.HasParent());
}

TEST_F(PackageTests, MethodHasParentReturnsFalsIfPackageHasNoParent) {
  ASSERT_FALSE(parent_package_.HasParent());
}

}  // namespace tests