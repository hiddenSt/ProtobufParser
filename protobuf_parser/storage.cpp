#include "storage.hpp"

namespace protobuf_parser {

Storage::Storage(Storage&& other) noexcept
    : messages_(std::move(other.messages_)),
      files_(std::move(other.files_)),
      packages_(std::move(other.packages_)),
      directories_(std::move(other.directories_)) {
}

}  // namespace protobuf_parser