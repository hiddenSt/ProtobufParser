#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
#include <protobuf_parser/protobuf_storage.hpp>

namespace protobuf_parser {
namespace view {

template <typename T, typename Serializer>
class View {
 public:
  View() = delete;
  explicit View(T* root, ProtobufStorage& storage, const Serializer& serializer);
  ~View() = default;

  std::string Serialize();

 private:
  Serializer serializer_;
  ProtobufStorage& storage_;
  T* root_;
};

template <typename T, typename Serializer>
View<T, Serializer>::View(T* root, ProtobufStorage& storage, const Serializer& serializer)
    : root_(root), serializer_(serializer), storage_(storage) {
}

template <typename T, typename Serializer>
std::string View<T, Serializer>::Serialize() {
  for (auto& message = storage_.Begin(root_); message != storage_.End<T>(); ++message) {
    serializer_.AddMessage(*message);
  }
  return serializer_.Serialize();
}

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
