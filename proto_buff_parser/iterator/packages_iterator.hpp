#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_

#include <proto_buff_parser/package.hpp>

namespace proto_buff_parser {
namespace iterator {

class PackagesIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Package& CurrentPackage() = 0;
};

}  // namespace iterator
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_PACKAGES_ITERATOR_HPP_
