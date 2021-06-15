#include "enum.hpp"

namespace protobuf_parser {

Enum::Enum() : file_(nullptr) {
}

const File& Enum::GetFile() const {
  return *file_;
}

const std::string& Enum::GetName() const {
  return name_;
}

const std::map<std::size_t, std::string>& Enum::GetValues() const {
  return values_;
}

Enum::Enum(Enum&& other) noexcept
    : Element(std::move(other)),
      name_(std::move(other.name_)),
      values_(std::move(other.values_)),
      reserved_numbers_(std::move(other.reserved_numbers_)),
      file_(other.file_) {
  other.file_ = nullptr;
}

Enum& Enum::operator=(Enum&& other) noexcept {
  name_ = std::move(other.name_);
  values_ = std::move(other.values_);
  reserved_numbers_ = std::move(other.reserved_numbers_);
  file_ = other.file_;
  other.file_ = nullptr;
  return *this;
}

std::map<std::string, std::string> Enum::Serialize() const {
  std::map<std::string, std::string> serialized_enum;
  serialized_enum["id"] = std::to_string(this->GetId());
  serialized_enum["name"] = name_;
  serialized_enum["file_id"] = std::to_string(file_->GetId());
  return serialized_enum;
}

}  // namespace protobuf_parser