#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_

#include <string>

namespace protobuf_parser {
namespace builders {
class PackageBuilder;
}

class Package {
 public:
  Package() = default;

  bool HasParent() const noexcept;
  const Package& GetParentPackage() const noexcept;
  const std::string& GetName() const;

 private:
  friend class builders::PackageBuilder;

  std::string name_;
  Package* parent_package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_
