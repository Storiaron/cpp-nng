//
// Created by User on 2024. 02. 21..
//

#include <sstream>
#include <iostream>
#include "DataParser.h"

std::vector<std::string> DataParser::parseData(const std::vector<std::string>& data) {
    StreetMap streetInfo;
    std::string evenDuplications;
    std::string oddDuplications;
    for (const auto& line : data) {
        StreetIdInfoPair lineInfo = parseLine(line);
        std::pair<std::string, std::set<int>> duplicationInfo = getDuplicationInfo(streetInfo, std::move(lineInfo));
        duplicationInfoToText(duplicationInfo, evenDuplications, oddDuplications);
    }
    return {evenDuplications, oddDuplications};
}

void DataParser::duplicationInfoToText(std::pair<std::string, std::set<int>> duplicationInfo,
                                                           std::string& evenDuplications, std::string& oddDuplications) {

    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;
    for(int num : duplicationInfo.second) {
        if(num % 2 == 0) {
            evenNumbers.push_back(num);
        }
        else {
            oddNumbers.push_back(num);
        }
    }
    evenDuplications += duplicationInfo.first + std::to_string(evenNumbers.at(0)) + "-" + std::to_string(*(evenNumbers.end() - 1));
    oddDuplications += duplicationInfo.first + std::to_string(oddNumbers.at(0)) + "-" + std::to_string(*(oddNumbers.end() - 1));
}

StreetIdInfoPair DataParser::parseLine(const std::string &line) {
    StreetIdInfoPair lineData;
    std::vector<std::string> stuff = splitLine(line, ',');
    lineData.first = std::move(buildStreetIdentifier(stuff));
    lineData.second = std::move(buildNumberInfo(stuff));
    return lineData;
}

std::unique_ptr<StreetIdentifier> DataParser::buildStreetIdentifier(std::vector<std::string> info) {
    std::unique_ptr<StreetIdentifier> streetIdentifier = std::make_unique<StreetIdentifier>();
    try {
        streetIdentifier->setStreetName(info.at(16));
        streetIdentifier->setStreetType(info.at(17));
    }
    catch (...) {
        std::cout<< "street error";
    }
    return streetIdentifier;
}

std::unique_ptr<NumberInfo> DataParser::buildNumberInfo(std::vector<std::string> info) {
    std::unique_ptr<NumberInfo> numberInfo = std::make_unique<NumberInfo>();
    std::set<int> numbers;
    if(!info.at(20).empty()) {
        int start = std::stoi(info.at(21));
        int end = std::stoi(info.at(22));
        if(info.at(21).at(0) == 'M') {
            while(start <= end) {
                numbers.insert(start);
                start++;
            }
        }
        else {
            while(start <= end) {
                numbers.insert(start);
                start += 2;
            }
        }
    }
    if(!info.at(23).empty()) {
        int start = std::stoi(info.at(24));
        int end = std::stoi(info.at(25));
        if(info.at(21).at(0) == 'M') {
            while(start <= end) {
                numbers.insert(start);
                start++;
            }
        }
        else {
            while(start <= end) {
                numbers.insert(start);
                start += 2;
            }
        }
    }
    numberInfo->setNumbers(numbers);
    return numberInfo;
}

std::vector<std::string> DataParser::splitLine(std::string line, char delimiter) {
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

std::pair<std::string, std::set<int>> DataParser::getDuplicationInfo(StreetMap& streetInfo, StreetIdInfoPair data) {
    for (auto& pair : streetInfo) {
        if (*pair.first == *data.first) {
            return std::make_pair(data.first->getStreetName() + data.first->getStreetType(), pair.second->getDuplicateNumbers(*data.second));
        }
    }
    streetInfo.insert(std::move(data));
    return {};
}