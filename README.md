# ProtoBuff parser to json

This is a wrapper around google protobuf runtime library

## Prerequisites
Before you begin, ensure you have met the following requirements:
* cmake
* [protobuf-cpp-3.15.8](https://github.com/protocolbuffers/protobuf/)
* compiler supporting ``C++17``

### Third-party
* [nlohmann/json](https://github.com/nlohmann/json)
* [p-ranav/argparse](https://github.com/p-ranav/argparse)
* [google test](https://github.com/google/googletest)

## Installing Parser

To install Parser, follow these steps:
In your build directory run<br><br>
Linux
```shell script
cmake --build path_to_sources -DPROTOBUF_PARSER_CONSOLE_UTILITY=ON
```

After build go to ``console_utility`` dir inside your build directory<br><br>
Linux
```shell script
cd console_utility
```

Execute binary to see available options and usage pattern<br><br>
Linux
```shell script
./protobuf_parser_utility -h
```

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