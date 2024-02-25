#include <iostream>
#include "input_processing/FileReader.h"
#include "logic/DuplicateFinder.h"
#include "output_handling/Logger.h"
#include "Application.h"

int main() {
    std::locale::global(std::locale("hu_HU.UTF-8"));
    FileReader fileReader;
    Logger logger;
    DataStreetInfoMapper dataStreetInfoMapper;
    DuplicateFinder duplicateFinder;
    Application application(dataStreetInfoMapper, fileReader, logger, duplicateFinder);
    const std::string inputFilePath = "../task/network.mid";
    application.run(inputFilePath);
    return 0;
}
