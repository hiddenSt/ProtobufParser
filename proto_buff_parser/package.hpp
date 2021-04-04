#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_

#include <string>

namespace proto_buff_parser {

class Package {
 public:
  explicit Package(const std::string& name, Package& parent_package);

  Package& GetParentPackage();
  const std::string& GetName() const;

 private:
  std::string name_;
  Package& parent_package_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_
