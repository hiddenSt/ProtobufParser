#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_STUB_MULTIPLE_ERROR_COLLECTOR_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_STUB_MULTIPLE_ERROR_COLLECTOR_HPP_

#include <google/protobuf/compiler/importer.h>

namespace protobuf_parser {

class StubMultipleErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector {
 public:
  void AddError(const std::string& filename, int line, int column,
                const std::string& message) override;
  void AddWarning(const std::string& filename, int line, int column,
                  const std::string& message) override;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_STUB_MULTIPLE_ERROR_COLLECTOR_HPP_
