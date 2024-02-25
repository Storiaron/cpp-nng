//
// Created by User on 2024. 02. 24..
//

#ifndef CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_
#define CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_

#include <string>
#include <map>
#include "../logic/DuplicateFinder.h"
std::map<std::string, int> informationIndeces{
    {"STREET_NAME" , 16},
    {"STREET_TYPE" , 17},
    {"LEFT_SIDE_NUMBERING_SCHEME", 20},
    {"LEFT_SIDE_STARTING_NUMBER", 21},
    {"LEFT_SIDE_ENDING_NUMBER", 22},
    {"RIGHT_SIDE_NUMBERING_SCHEME", 23},
    {"RIGHT_SIDE_STARTING_NUMBER", 24},
    {"RIGHT_SIDE_ENDING_NUMBER", 25}
};
class DataStreetInfoMapper {
 public:
  using StreetIdInfoPair = std::pair<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>;
  std::vector<StreetIdInfoPair>& parseData(const std::vector<std::string>& data);
 private:
  std::vector<std::string> splitLine(std::string line, char delimiter);
  StreetIdInfoPair parseLine(const std::string& line);
  std::unique_ptr<StreetIdentifier> buildStreetIdentifier(const std::vector<std::string>& info);
  std::unique_ptr<NumberInfo> buildNumberInfo(const std::vector<std::string>& info);
};
#endif //CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_
/*
 * DuplicateFinder::StreetIdInfoPair DuplicateFinder::parseLine(const std::string &line) {
    StreetIdInfoPair lineData;
    std::vector<std::string> stuff = splitLine(line, ',');
    lineData.first = std::move(buildStreetIdentifier(stuff));
    lineData.second = std::move(buildNumberInfo(stuff));
    return lineData;
}

std::unique_ptr<StreetIdentifier> DuplicateFinder::buildStreetIdentifier(std::vector<std::string> info) {
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

std::unique_ptr<NumberInfo> DuplicateFinder::buildNumberInfo(std::vector<std::string> info) {
    std::unique_ptr<NumberInfo> numberInfo = std::make_unique<NumberInfo>();
    std::set<int> numbers;
    if(!info.at(20).empty()) {
        int start = std::stoi(info.at(21));
        int end = std::stoi(info.at(22));
        if(info.at(20).at(0) == 'M') {
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
        if(info.at(23).at(0) == 'M') {
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

std::vector<std::string> DuplicateFinder::splitLine(std::string line, char delimiter) {
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
 */