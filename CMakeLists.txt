cmake_minimum_required(VERSION 3.26)
project(cpp_nng)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_nng main.cpp
        input_output/FileReader.cpp
        input_output/FileReader.h
        DataParser.cpp
        DataParser.h
        model/StreetIdentifier.cpp
        model/StreetIdentifier.h
        model/NumberInfo.cpp
        model/NumberInfo.h
        input_output/Logger.cpp
        input_output/Logger.h
)
