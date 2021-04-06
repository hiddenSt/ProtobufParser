#include "directory.hpp"

namespace protobuf_parser {

Directory::Directory(const std::string& name) : name_(name), parent_directory_(nullptr) {
}

Directory::Directory(const std::string& name, protobuf_parser::Directory* parent_directory)
    : name_(name), parent_directory_(parent_directory) {
}

const std::string& Directory::GetName() const {
  return name_;
}

}  // namespace protobuf_parser
