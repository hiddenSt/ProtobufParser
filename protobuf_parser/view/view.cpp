#include "view.hpp"

namespace protobuf_parser {
namespace view {

template <>
void View<Directory>::EmplaceElementChildren(const Directory* directory, std::queue<const Directory*>& elements_queue) {
  for (auto& dir: storage_->directories_) {
    if (dir.GetParentDirectory().GetName() == directory->GetName()) {
      elements_queue.emplace(&dir);
    }
  }
}

template <>
void View<Directory>::AddElementsMessages(const Directory* element) {
}

template <>
void View<Package>::EmplaceElementChildren(const Package* package, std::queue<const Package*>& elements_queue) {
  for (auto& a_package: storage_->packages_) {
    if (a_package.GetParentPackage().GetName() == package->GetName()) {
      elements_queue.emplace(&a_package);
    }
  }
}

template <>
void View<Package>::AddElementsMessages(const Package* element) {

}

}
}