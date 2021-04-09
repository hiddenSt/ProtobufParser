#include "stub_multiple_error_collector.hpp"

namespace protobuf_parser {

void StubMultipleErrorCollector::AddError(const std::string& filename, int line, int column,
                                          const std::string& message) {
}

void StubMultipleErrorCollector::AddWarning(const std::string& filename, int line, int column,
                                            const std::string& message) {
  MultiFileErrorCollector::AddWarning(filename, line, column, message);
}

}  // namespace protobuf_parser