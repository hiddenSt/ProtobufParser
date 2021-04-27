#include <iostream>
#include <string>
#include <filesystem>

#include <argparse/argparse.hpp>
#include <protobuf_parser/parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>
#include <protobuf_parser/parse_exception.hpp>

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

  protobuf_parser::Parser parser(root_path);
  try {
    parser.Parse();
  } catch (const protobuf_parser::ParseException& parse_exception) {
    std::cerr << parse_exception.what() << "\n";
  }
  auto storage = std::move(parser.GetStorage());

  auto parse_source = program.get<std::string>("parse_source");
  if (program["--package"] == true) {
    auto view = storage.GetPackageView(parse_source);
    protobuf_parser::serializers::JsonSerializer serializer{view};
    std::cout << serializer.SerializeMessages() << "\n";
    std::cout << serializer.SerializeDirectories() << "\n";
    std::cout << serializer.SerializeFiles() << "\n";
    std::cout << serializer.SerializePackages() << "\n";
  } else {
    auto view = storage.GetDirectoryView(parse_source);
    protobuf_parser::serializers::JsonSerializer serializer{view};
    std::cout << serializer.SerializeMessages() << "\n";
    std::cout << serializer.SerializeDirectories() << "\n";
    std::cout << serializer.SerializeFiles() << "\n";
    std::cout << serializer.SerializePackages() << "\n";
  }
  return 0;
}
