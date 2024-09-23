cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MyProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем Boost
find_package(Boost REQUIRED COMPONENTS serialization)

# Указываем директорию заголовочных файлов
include_directories(${Boost_INCLUDE_DIRS} inc)

# Добавляем исходные файлы
set(SOURCES
    src/compres.cpp
    src/hafmanTable.cpp
    src/hafmanTree.cpp
    src/main.cpp
    src/output.cpp
    src/zip.cpp
)

# Создаем исполняемый файл
add_executable(MyProject ${SOURCES})

# Линкуем Boost.Serialization
target_link_libraries(MyProject ${Boost_LIBRARIES})

# Устанавливаем конфигурацию сборки по умолчанию
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Устанавливаем флаги компилятора для различных типов сборки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
