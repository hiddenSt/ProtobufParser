#include <iostream>
#include <string>
#include <filesystem>

#include <argparse/argparse.hpp>
#include <protobuf_parser/parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program{"protobuf_parser", "1.0"};
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

  std::filesystem::path root_path{program.get<std::string>("source_directory")};
  protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer> parser(root_path);
  auto parse_source = program.get<std::string>("parse_source");
  if (program["--package"] == true) {
    try {
      std::cout << parser.SerializePackage(parse_source) << std::endl;
    } catch (std::runtime_error& error) {
      std::cerr << error.what() << std::endl;
      return 1;
    }
  } else {
    std::filesystem::path directory_path{parse_source};
    try {
      std::cout << parser.SerializeDirectory(directory_path) << std::endl;
    } catch (std::runtime_error& error) {
      std::cerr << error.what() << std::endl;
      return 1;
    }
  }
  return 0;
}
