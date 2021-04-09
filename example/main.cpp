#include <iostream>
#include <string>

#include <argparse/argparse.hpp>
#include <protobuf_parser/protobuf_parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program{"protobuf_parser"};

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> parser(program.get<std::string>("source"));
  std::cout << parser.SerializeDirectory();
  return 0;
}