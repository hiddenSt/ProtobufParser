#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_

#include <string>

#include <protobuf_parser/package.hpp>
#include <protobuf_parser/iterator/packages_iterator.hpp>

namespace protobuf_parser {
namespace container {

class PackagesContainer {
 public:
  virtual void AddPackage(const Package& package) = 0;
  virtual Package& GetPackage(const std::string& name) = 0;
  virtual iterator::PackagesIterator& GetIterator() = 0;
  virtual ~PackagesContainer() = 0;
};

}  // namespace container
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PACKAGES_CONTAINER_HPP_
