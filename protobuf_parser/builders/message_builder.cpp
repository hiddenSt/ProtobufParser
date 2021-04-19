#include "message_builder.hpp"

namespace protobuf_parser {
namespace builders {

Message MessageBuilder::BuildMessage(const google::protobuf::Descriptor* descriptor, File* file) {
  Message message{descriptor->name(), file};

  return message;
}

}
}