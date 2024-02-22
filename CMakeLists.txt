cmake_minimum_required(VERSION 3.26)
project(cpp_nng)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_nng main.cpp
        FileReader.cpp
        FileReader.h
        DataParser.cpp
        DataParser.h
        model/StreetIdentifier.cpp
        model/StreetIdentifier.h
        model/NumberInfo.cpp
        model/NumberInfo.h
)
