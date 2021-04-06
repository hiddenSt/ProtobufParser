#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_

#include <string>

#include <protobuf_parser/parse_element.hpp>
#include <protobuf_parser/iterator.hpp>

namespace protobuf_parser {

class Package : public ParseElement {
 public:
  Package();
  explicit Package(const std::string& name);
  explicit Package(const std::string& name, Package* const parent_package);
  explicit Package(const std::string&& name) noexcept;
  explicit Package(std::string&& name, Package* const parent_package) noexcept;

  Package& operator=(const Package& other);

  const Package* const GetParentPackage();
  const std::string& GetName() const;


 private:
  std::string name_;
  Package* const parent_package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_PACKAGE_HPP_
