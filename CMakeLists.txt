cmake_minimum_required(VERSION 3.26)
project(cpp_nng)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_nng main.cpp
        input_processing/FileReader.cpp
        input_processing/FileReader.h
        logic/DuplicateFinder.cpp
        logic/DuplicateFinder.h
        model/StreetIdentifier.cpp
        model/StreetIdentifier.h
        model/NumberInfo.cpp
        model/NumberInfo.h
        output_handling/Logger.cpp
        output_handling/Logger.h
        input_processing/DataStreetInfoMapper.cpp
        input_processing/DataStreetInfoMapper.h
)
