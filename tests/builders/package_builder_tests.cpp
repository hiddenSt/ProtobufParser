#include <gtest/gtest.h>

#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

TEST(PackageBuilderTests, CanCreatePackageBuilderBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::PackageBuilder{});
}

TEST(PackageBuilderTests, CanSetUpName) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  ASSERT_NO_THROW(builder.SetUpName(name));
}

TEST(PackageBuilderTests, CanGetPackageName) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(name);
  ASSERT_NO_THROW(builder.GetName());
}

TEST(PackageBuilderTests, MethodGetPackageNameReturnsCorrectName) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(name);
  ASSERT_EQ(builder.GetPackage().GetName(), name);
}

TEST(PackageBuilderTests, CanGetPackage) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(name);
  ASSERT_NO_THROW(builder.GetPackage());
}

TEST(PackageBuilderTests, MethodGetPackageReturnsCorrectPackage) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(name);
  auto package = std::move(builder.GetPackage());
  ASSERT_EQ(package.GetName(), name);
}

TEST(PackageBuilderTests, CanSetUpParent) {
  std::string parent_name{"parent_name"};
  std::string child_name{"child_name"};

  protobuf_parser::builders::PackageBuilder parent_builder{};
  protobuf_parser::builders::PackageBuilder child_builder{};
  parent_builder.SetUpName(parent_name);
  child_builder.SetUpName(child_name);

  auto parent_package = std::move(parent_builder.GetPackage());
  ASSERT_NO_THROW(child_builder.SetUpParent(&parent_package));
}

TEST(PackageBuilderTests, CanGetParent) {
  std::string parent_name{"parent_name"};
  std::string child_name{"child_name"};

  protobuf_parser::builders::PackageBuilder parent_builder{};
  protobuf_parser::builders::PackageBuilder child_builder{};
  parent_builder.SetUpName(parent_name);
  child_builder.SetUpName(child_name);

  auto parent_package = std::move(parent_builder.GetPackage());
  child_builder.SetUpParent(&parent_package);
  auto child_package = std::move(child_builder.GetPackage());

  ASSERT_NO_THROW(&child_package.GetParentPackage());
}

TEST(PackageBuilderTests, MethodGetParentReturnsCorrectParent) {
  std::string parent_name{"parent_name"};
  std::string child_name{"child_name"};

  protobuf_parser::builders::PackageBuilder parent_builder{};
  protobuf_parser::builders::PackageBuilder child_builder{};
  parent_builder.SetUpName(parent_name);
  child_builder.SetUpName(child_name);

  auto parent_package = std::move(parent_builder.GetPackage());
  child_builder.SetUpParent(&parent_package);
  auto child_package = std::move(child_builder.GetPackage());

  ASSERT_EQ(&child_package.GetParentPackage(), &parent_package);
}

TEST(PackageBuilderTests, MethodIsChildOfReturnsTrueIfArgumentIsParebtPackageName) {
  std::string parent_name{"parent_name"};
  std::string child_name{"parent_name.child_name"};

  protobuf_parser::builders::PackageBuilder child_builder{};
  child_builder.SetUpName(child_name);

  ASSERT_TRUE(child_builder.IsChildOf(parent_name));
}

TEST(PackageBuilderTests, MethodIsParentReturnsFalseIfArgumentIsNotChildPackageName) {
  std::string parent_name{"parent_name"};
  std::string child_name{"parent_name.cool_name.child_name"};

  protobuf_parser::builders::PackageBuilder child_builder{};
  child_builder.SetUpName(child_name);


  ASSERT_FALSE(child_builder.IsChildOf(parent_name));
}

}  // namespace tests
