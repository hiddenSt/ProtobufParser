#include <gtest/gtest.h>

#include <protobuf_parser/parsed_elements/package.hpp>

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
  ASSERT_EQ(package.GetParentPackage(), &parent_package);
}

TEST(PackageTests, ReturnsTrueIfCompareEqualPackages) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};

  protobuf_parser::Package parent_package{parent_package_name};

  protobuf_parser::Package package{package_name, &parent_package};
  protobuf_parser::Package package2{package_name, &parent_package};

  ASSERT_TRUE(package == package2);
}

TEST(PackageTests, ReturnsFalseIfComparePackagesWithDifferentNames) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};
  std::string package_name2{"DifferentPackageName"};

  protobuf_parser::Package parent_package{parent_package_name};

  protobuf_parser::Package package{package_name, &parent_package};
  protobuf_parser::Package package2{package_name2, &parent_package};

  ASSERT_FALSE(package == package2);
}

TEST(PackageTests, ReturnsFalseIfComparePackagesWithDifferentParents) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};

  protobuf_parser::Package parent_package{parent_package_name};

  protobuf_parser::Package package{package_name, &parent_package};
  protobuf_parser::Package package2{package_name, nullptr};

  ASSERT_FALSE(package == package2);
}

}  // namespace tests