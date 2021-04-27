# ProtoBuff parser to json

This is a wrapper around google protobuf runtime library

## Prerequisites
Before you begin, ensure you have met the following requirements:
* cmake
* [protobuf-cpp-3.15.8](https://github.com/protocolbuffers/protobuf/)
* compiler supporting ``C++17``
To build for msvc you additionaly need `vcpkg`

### Third-party
* [nlohmann/json](https://github.com/nlohmann/json)
* [p-ranav/argparse](https://github.com/p-ranav/argparse)
* [google test](https://github.com/google/googletest)

## Installing Parser

To install Parser, follow these steps:
In your build directory run<br><br>
* Linux
```shell script
cmake --build path_to_sources -DPROTOBUF_PARSER_CONSOLE_UTILITY=ON
```
After build go to ``console_utility`` dir inside your build directory<br><br>
```shell script
cd console_utility
```
Execute binary to see available options and usage pattern<br><br>
```shell script
./protobuf_parser_utility -h
```
* Widnows
```shell script
vcpkg install protobuf protobuf:x64-windows
```
Run cmake
```shell script
cmake -DPROTOBUF_PARSER_CONSOLE_UTILITY=On -DCMAKE_TOOLCHAIN_FILE=`path to vcpkg.cmake` -- build ..
```
After that open solution in build directory using Visual Studio and build.

## Running tests
``WARNING`` For correct tests run ensure that build directory is placed inside the root source directory<br>
To enable tests run cmake with flag ``-DPROTOBUF_PARSER_TESTS=ON``<br><br>
Linux
```shell script
cmake --build -DPROTOBUF_PARSER_TESTS=ON ..
```

Execute binary ``tests/run_protobuf_parser_tests`` to run tests
```shell script
./tests/run_protobuf_parser_tests
```

## Contact
If you want to contact me you can reach me at
* Telegram: ``@hiddenSt1``
* Email: ``hiddenstmail@gnail.com``
