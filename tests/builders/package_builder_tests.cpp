#include <gtest/gtest.h>

#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

TEST(PackageBuilderTests, CanCreatePackageBuilderBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::PackageBuilder{});
}

TEST(PackageBuilderTests, CanSetUpName) {
  std::string name{"package_name"};
  protobuf_parser::builders::PackageBuilder builder{};
  builder.SetUpName(name);
  ASSERT_EQ(builder.GetPackage().GetName(), name);
}

TEST(PackageBuilderTests, CanSetUpParent) {
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

}
