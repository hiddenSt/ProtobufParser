#include "stub_multiple_error_collector.hpp"
#include <protobuf_parser/parse_exception.hpp>

namespace protobuf_parser {

void StubMultipleErrorCollector::AddError(const std::string& filename, int line, int column,
                                          const std::string& message) {
  throw ParseException{filename, line, column, message};
}

void StubMultipleErrorCollector::AddWarning(const std::string& filename, int line, int column,
                                            const std::string& message) {
  MultiFileErrorCollector::AddWarning(filename, line, column, message);
}

}  // namespace protobuf_parser