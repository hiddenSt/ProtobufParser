#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_

#include <string>

#include <proto_buff_parser/package.hpp>
#include <proto_buff_parser/iterator/packages_iterator.hpp>

namespace proto_buff_parser {
namespace container {

class PackagesContainer {
 public:
  virtual void AddPackage(const Package& package) = 0;
  virtual Package& GetPackage(const std::string& name) = 0;
  virtual iterator::PackagesIterator GetIterator() = 0;
};

}  // namespace container
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_
