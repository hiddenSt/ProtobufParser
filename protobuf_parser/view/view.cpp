#include "view.hpp"

namespace protobuf_parser {
namespace view {

template <>
void View<Directory>::EmplaceElementChildren(const Directory* directory,
                                             std::queue<const Directory*>& elements_queue) {
  for (auto& dir : storage_->directories_) {
    if (dir.HasParent() && dir.GetParentDirectory().GetName() == directory->GetName()) {
      elements_queue.emplace(&dir);
    }
  }
}

template <>
void View<Directory>::AddElementsMessages(const Directory* directory) {
  for (auto& message : storage_->messages_) {
    if (message.GetDirectory().GetName() == directory->GetName()) {
      messages_.push_back(&message);
    }
  }
}

template <>
void View<Package>::EmplaceElementChildren(const Package* package,
                                           std::queue<const Package*>& elements_queue) {
  for (auto& a_package : storage_->packages_) {
    if (a_package.HasParent() && a_package.GetParentPackage().GetName() == package->GetName()) {
      elements_queue.emplace(&a_package);
    }
  }
}

template <>
void View<Package>::AddElementsMessages(const Package* package) {
  for (auto& message : storage_->messages_) {
    if (message.GetPackage().GetName() == package->GetName()) {
      messages_.push_back(&message);
    }
  }
}

}  // namespace view
}  // namespace protobuf_parser