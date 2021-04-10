#include <iostream>
#include <string>

#include <argparse/argparse.hpp>
#include <protobuf_parser/protobuf_parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program{"protobuf_parser"};
  program.add_argument("source_directory")
      .help("Source directory to parse from");
  program.add_argument("parse_source")
      .help("Name of the source to parse from. Default - directory");
  program.add_argument("--package")
      .help("Set parse source to package name")
      .default_value(false)
      .implicit_value(true);

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }

  protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> parser(program.get<std::string>("source"));
  auto parse_source = program.get<std::string>("parse_source");
  if (program["--package"] == true) {
    std::cout << parser.SerializePackage(parse_source);
  } else {
    std::cout << parser.SerializeDirectory(parse_source);
  }
  return 0;
}