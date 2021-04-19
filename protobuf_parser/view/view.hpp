#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
#include <protobuf_parser/storage.hpp>

namespace protobuf_parser {
namespace view {

template <typename T>
class View {
 public:
  View() = delete;
  explicit View(T* root);
  ~View() = default;

  std::string Serialize();

 private:
  Storage& storage_;
  T* root_;
};

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
