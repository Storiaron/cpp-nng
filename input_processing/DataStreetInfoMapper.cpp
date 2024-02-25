//
// Created by User on 2024. 02. 24..
//

#include <iostream>
#include <sstream>
#include "DataStreetInfoMapper.h"
std::vector<DataStreetInfoMapper::StreetIdInfoPair> DataStreetInfoMapper::parseData(const std::vector<std::string>& data) {
    std::vector<DataStreetInfoMapper::StreetIdInfoPair> streetInfo;
    for (const auto& line : data) {
        streetInfo.push_back(parseLine(line));
    }
    return streetInfo;
}
std::vector<std::string> DataStreetInfoMapper::splitLine(std::string line, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        while (!token.empty() && token.front() == '"')
            token.erase(token.begin());
        while (!token.empty() && token.back() == '"')
            token.pop_back();
        tokens.push_back(token);
    }
    return tokens;
}
DataStreetInfoMapper::StreetIdInfoPair DataStreetInfoMapper::parseLine(const std::string &line) {
    StreetIdInfoPair lineData;
    std::vector<std::string> lineInformationSplit = splitLine(line, ',');
    lineData.first = std::move(buildStreetIdentifier(lineInformationSplit));
    lineData.second = std::move(buildNumberInfo(lineInformationSplit));
    return lineData;
}

std::unique_ptr<StreetIdentifier> DataStreetInfoMapper::buildStreetIdentifier(const std::vector<std::string>& info) {
    std::unique_ptr<StreetIdentifier> streetIdentifier = std::make_unique<StreetIdentifier>();
        streetIdentifier->setStreetName(info.at(informationIndeces["STREET_NAME"]));
        streetIdentifier->setStreetType(info.at(informationIndeces["STREET_TYPE"]));
    return streetIdentifier;
}

std::unique_ptr<NumberInfo> DataStreetInfoMapper::buildNumberInfo(const std::vector<std::string>& info) {
    std::unique_ptr<NumberInfo> numberInfo = std::make_unique<NumberInfo>();
    std::set<int> numbers;
    if (!info.at(informationIndeces["LEFT_SIDE_NUMBERING_SCHEME"]).empty()) {
        int start = std::stoi(info.at(informationIndeces["LEFT_SIDE_STARTING_NUMBER"]));
        int end = std::stoi(info.at(informationIndeces["LEFT_SIDE_ENDING_NUMBER"]));
        if (info.at(informationIndeces["LEFT_SIDE_NUMBERING_SCHEME"]).at(0) == 'M') {
            while (start <= end) {
                numbers.insert(start);
                start++;
            }
        } else {
            while (start <= end) {
                numbers.insert(start);
                start += 2;
            }
        }
    }
    if (!info.at(informationIndeces["RIGHT_SIDE_NUMBERING_SCHEME"]).empty()) {
        int start = std::stoi(info.at(informationIndeces["RIGHT_SIDE_STARTING_NUMBER"]));
        int end = std::stoi(info.at(informationIndeces["RIGHT_SIDE_ENDING_NUMBER"]));
        if (info.at(informationIndeces["RIGHT_SIDE_NUMBERING_SCHEME"]).at(0) == 'M') {
            while (start <= end) {
                numbers.insert(start);
                start++;
            }
        } else {
            while (start <= end) {
                numbers.insert(start);
                start += 2;
            }
        }
    }

    numberInfo->setNumbers(numbers);
    return numberInfo;
}