#include <iostream>
#include <string>

#include <protobuf_parser/protobuf_parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "At least 2 parameters required";
    return 1;
  }
  protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> parser{std::string{argv[2]}};

  if (argv[1] == "--package") {
    std::cout << parser.Serializepackage(std::string{argv[2]});
    return 0;
  }

  if (argv[1] == "--directory") {
    std::cout << parser.SerializeDirectory(std::string{argv[2]});
    return 0;
  }

  std::cerr << "Error";
  return 1;
}