#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FILES_ITERATOR_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FILES_ITERATOR_HPP_

#include <protobuf_parser/parse_elements/file.hpp>

namespace protobuf_parser {
namespace iterator {

class FilesIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual File& GetCurrentFile() = 0;
  virtual ~FilesIterator() = 0;
};

}  // namespace iterator
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FILES_ITERATOR_HPP_
