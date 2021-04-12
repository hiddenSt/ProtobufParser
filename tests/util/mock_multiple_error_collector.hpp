#ifndef PROTOBUF_PARSER_TESTS_UTIL_MOCK_MULTIPLE_ERROR_COLLECTOR_HPP_
#define PROTOBUF_PARSER_TESTS_UTIL_MOCK_MULTIPLE_ERROR_COLLECTOR_HPP_

#include <google/protobuf/compiler/importer.h>

namespace tests {
namespace util {
class MockMultipleErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector {
 public:
  void AddError(const std::string& filename, int line, int column,
                const std::string& message) override {
  }

  void AddWarning(const std::string& filename, int line, int column,
                  const std::string& message) override {
  }
};

}  // namespace util
}  // namespace tests
#endif  // PROTOBUF_PARSER_TESTS_UTIL_MOCK_MULTIPLE_ERROR_COLLECTOR_HPP_
