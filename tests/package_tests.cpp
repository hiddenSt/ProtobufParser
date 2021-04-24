#include <gtest/gtest.h>

#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

TEST(PackageTests, CanGetPackageName) {
  std::string package_name{"PackageName1"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(package_name);

  auto package = std::move(builder.GetPackage());
  ASSERT_EQ(package.GetName(), package_name);
}

TEST(PackageTests, CanGetParentPackage) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};
  protobuf_parser::builders::PackageBuilder child_builder{};
  protobuf_parser::builders::PackageBuilder parent_builder{};

  parent_builder.SetUpName(parent_package_name);
  child_builder.SetUpName(package_name);

  auto parent = std::move(parent_builder.GetPackage());

  child_builder.SetUpParent(&parent);
  auto child = std::move(child_builder.GetPackage());
  ASSERT_EQ(&child.GetParentPackage(), &parent);
}

TEST(PackageTests, MethodHasParentReturnsTrueIfPackageHasParent) {
  std::string parent_package_name{"ParentPackageName1"};
  std::string package_name{"PackageName"};
  protobuf_parser::builders::PackageBuilder child_builder{};
  protobuf_parser::builders::PackageBuilder parent_builder{};

  parent_builder.SetUpName(parent_package_name);
  child_builder.SetUpName(package_name);

  auto parent = std::move(parent_builder.GetPackage());

  child_builder.SetUpParent(&parent);
  auto child = std::move(child_builder.GetPackage());
  ASSERT_TRUE(child.HasParent());
}

TEST(PackageTests, MethodHasParentReturnsFalsIfPackageHasNoParent) {
  std::string parent_package_name{"ParentPackageName1"};
  protobuf_parser::builders::PackageBuilder child_builder{};
  auto child = std::move(child_builder.GetPackage());

  ASSERT_FALSE(child.HasParent());
}

}  // namespace tests