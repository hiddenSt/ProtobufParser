#include <iostream>
#include <string>

#include <argparse/argparse.hpp>

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program{"protobuf_parser"};
  program.add_argument("-p", "--package").help("parse package with given name").default_value("false").implicit_value("true");
  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }
  return 0;
}