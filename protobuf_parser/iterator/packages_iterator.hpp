#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_

#include <protobuf_parser/package.hpp>

namespace protobuf_parser {
namespace iterator {

class PackagesIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Package& CurrentPackage() = 0;
};

}  // namespace iterator
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_
