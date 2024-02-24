//
// Created by User on 2024. 02. 21..
//

#include <sstream>
#include <iostream>
#include "DataParser.h"

std::vector<std::string> DataParser::parseData(const std::vector<std::string>& data) {
    StreetMap streetInfo;
    std::string evenDuplications{"Even duplications: "};
    std::string oddDuplications{"Odd duplications: "};
    for (const auto& line : data) {
        StreetIdInfoPair lineInfo = parseLine(line);
        updateDuplicationInfo(streetInfo, std::move(lineInfo));
    }
    duplicationInfoToText(streetInfo, evenDuplications, oddDuplications);
    return {evenDuplications, oddDuplications};
}

void DataParser::duplicationInfoToText(StreetMap &duplicationInfo,
                                       std::string& evenDuplications, std::string& oddDuplications) {

    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;
    for(const auto& sg : duplicationInfo) {
        for (const int item : sg.second->getDuplicateNumbers()) {
            if(item % 2 == 0) {
                evenNumbers.push_back(item);
            }
            else {
                oddNumbers.push_back(item);
            }
        }
        if(!evenNumbers.empty()) {
            evenDuplications += sg.first->getStreetName() + " " +  sg.first->getStreetType() +  " : " +
                std::to_string(evenNumbers.at(0)) + "-" + std::to_string(evenNumbers.at(evenNumbers.size() - 1));
            evenDuplications += '\n';
        }
        if(!oddNumbers.empty()) {
            oddDuplications += sg.first->getStreetName() + " " + sg.first->getStreetType() + " : " +
                std::to_string(oddNumbers.at(0)) + "-" + std::to_string(oddNumbers.at(oddNumbers.size() - 1));
            oddDuplications += '\n';
        }
    }
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

void DataParser::updateDuplicationInfo(StreetMap& streetInfo, StreetIdInfoPair data) {
    for (auto& pair : streetInfo) {
        if (*pair.first == *data.first) {
            pair.second->updateNumberInfo(*data.second);
            return;
        }
    }
    streetInfo.insert(std::move(data));
}