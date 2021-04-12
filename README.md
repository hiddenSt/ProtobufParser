# ProtoBuff parser to json

Парсер protocol buffers 3 в json. Данная библиотека представляет собой обёртку над google protobuf c++ runtime api

## Зависимости
Для использования необходимо следующее:
* cmake
* [protobuf-cpp-3.15.8](https://github.com/protocolbuffers/protobuf/releases/download/v3.15.8/protobuf-cpp-3.15.8.tar.gz)
* компилятор поддерживающий ``C++20``

### Сторонние библиотеки устанавливаемые автоматически
* [nlohmann/json](https://github.com/nlohmann/json)
* [p-ranav/argparse](https://github.com/p-ranav/argparse)
* [google test](https://github.com/google/googletest)

## Использование

Есть два способа применения:
1) Как библиотека
2) Как консольная утилита

### Пример использования

Создайте парсер со своим сериалайзером. В библиотеке есть JsonSerializer
```c++
protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> parser('root_directory_to_parse');
```

Можно парсить messages по директории или по package. Будет возвращён std::string в формате указаноого сериалайзера
```
parser.SerializeDirectory('path_relative_to_the_root_directory')
parser.SerializeDirectory('package_name')
```

Для того чтобы реализовать свой парсер необходимо определить класс со следующими методами
```c++
class Serializer {
  public:
   void AddMessage(const Message& message);
   std::string Serialize();
};
```

## Запуск тестов
``WARNING`` Для корректной работы тестов папка сборки должна находится в корневой директории проекта<br>
Для запуска тестов необходимо вызвать cmake с флагом ``-DPROTOBUF_PARSER_TESTS=ON``

Исполняемый файл ``tests/run_protobuf_parser_tests`` для запуска тестов будет находится в директории сборки

## Сборка консольной утилиты
Для того чтобы собрать консольную утилиту необходимо вызвать cmake с флагом ``-DPROTOBUF_PARSER_CONSOLE_UTILITY=ON``
В диретории сборки будет находится исполняемый файл ``console_utility/protobuf_parser_utility``

### Использование консольной утилиты
При запуске утилиты первый позиционный параметр - директории для разбора, второй позиционный параметр - источник для парсинга (имя директории или package)
```shell script
./protobuf_parser_utility protos_files_dir dir1
```
Для вспомогательной информации запустите консольную утилиту с флагом ``-h``
Для того чтобы распарсить package необходимо указать параметр ``--package``
```shell script
./protobuf_parser_utility --package protos_files_dir package_name
```