#include "view.hpp"

namespace protobuf_parser {
namespace view {

template <>
void View<Directory>::EmplaceElementChildren(const Directory* directory,
                                             std::queue<const Directory*>& elements_queue) {
}

template <>
void View<Directory>::AddElementsMessages(const Directory* directory) {
}

template <>
void View<Package>::EmplaceElementChildren(const Package* package,
                                           std::queue<const Package*>& elements_queue) {
}

template <>
void View<Package>::AddElementsMessages(const Package* package) {
}

}  // namespace view
}  // namespace protobuf_parser