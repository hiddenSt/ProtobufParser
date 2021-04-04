#include <gtest/gtest.h>

#include <../protobuf_parser/package.hpp>

namespace tests {

TEST(PackageTests, CanGetPackageName) {
  std::string package_name{"PackageName1"};
  protobuf_parser::Package package{package_name};
  ASSERT_EQ(package.GetName(), package_name);
}

TEST(PackageTests, ReturnsNullptrIfHasNoParent) {
  std::string package_name{"PackageName1"};
  protobuf_parser::Package package{package_name};
  ASSERT_EQ(package.GetParentPackage(), nullptr);
}

TEST(PackageTests, CanGetParentPackage) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};

  protobuf_parser::Package parent_package{parent_package_name};

  protobuf_parser::Package package{package_name, &parent_package};
  ASSERT_EQ(package.GetParentPackage().GetName(), parent_package_name);
}

}  // namespace tests