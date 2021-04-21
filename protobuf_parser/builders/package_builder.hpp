#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_

#include <string>

#include <protobuf_parser/elements/package.hpp>

namespace protobuf_parser {
namespace builders {

class PackageBuilder {
 public:
  PackageBuilder() = default;

  void SetUpName(const std::string& name) noexcept;
  void SetUpParent(Package* parent) noexcept;
  const std::string& GetName() const;
  bool IsParent(const std::string& package_name);
  Package& GetPackage();

 private:
  Package package_;
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_PACKAGE_BUILDER_HPP_
