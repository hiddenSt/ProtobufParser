#include "file.hpp"

namespace proto_buff_parser {

proto_buff_parser::File::File(const std::string& name, const std::string& path)
    : name_(name), path_(path) {
}
const std::string& File::GetName() const noexcept {
  return name_;
}
const std::string& File::GetPath() const noexcept {
  return path_;
}

}  // namespace proto_buff_parser
