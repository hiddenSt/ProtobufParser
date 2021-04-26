#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_

#include <string>

#include <protobuf_parser/elements/package.hpp>

namespace protobuf_parser {
namespace builders {

class PackageBuilder {
 public:
  PackageBuilder() = default;
  PackageBuilder(PackageBuilder&& other) noexcept;
  PackageBuilder& operator=(PackageBuilder&& other) noexcept;

  // Non-copyable
  PackageBuilder(const PackageBuilder&) = delete;
  PackageBuilder& operator=(const PackageBuilder&) = delete;

  void SetUpName(const std::string& name) noexcept;
  void SetUpParent(Package* parent) noexcept;
  const std::string& GetName() const;
  bool IsChildOf(const std::string& package_name);
  Package& GetPackage();

 private:
  Package package_;
};

}  // namespace builders
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_
