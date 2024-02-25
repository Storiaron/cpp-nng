//
// Created by User on 2024. 02. 25..
//

#include "Application.h"

void Application::run(const std::string &inputFilePath) {
    std::vector<std::string> rawData = fileReader.readFile(inputFilePath);
    std::vector<DataStreetInfoMapper::StreetIdInfoPair> streetInfo = std::move(dataStreetInfoMapper.parseData(rawData));
    std::string evenDuplications{"Even duplications: \n"};
    std::string oddDuplications{"Odd duplications: \n"};
    duplicateFinder.getNumberDuplications(streetInfo, evenDuplications, oddDuplications);
    logger.logResult(evenDuplications);
    logger.logResult(oddDuplications);
}
