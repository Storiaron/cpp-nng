//
// Created by User on 2024. 02. 21..
//

#include <sstream>
#include <iostream>
#include "DuplicateFinder.h"

void DuplicateFinder::getNumberDuplications(std::vector<DataStreetInfoMapper::StreetIdInfoPair> &streetInfos,
                                            std::string &evenDuplications,
                                            std::string &oddDuplications) {
    std::map<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>> streetMap;
    for(auto& streetInfo : streetInfos) {
        updateDuplicationInfo(streetMap, streetInfo);
    }
}

void DuplicateFinder::duplicationInfoToText(std::map<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>& streetMap,
                                            std::string& evenDuplications, std::string& oddDuplications) {

    for(const auto& streetInfo : streetMap) {
        std::vector<int> evenNumbers;
        std::vector<int> oddNumbers;
        for (const int item : streetInfo.second->getDuplicateNumbers()) {
            if(item % 2 == 0) {
                evenNumbers.push_back(item);
            }
            else {
                oddNumbers.push_back(item);
            }
        }
        if(!evenNumbers.empty()) {
            evenDuplications += streetInfo.first->getStreetName() + " " +  streetInfo.first->getStreetType() +  " : " +
                std::to_string(evenNumbers.at(0)) + "-" + std::to_string(evenNumbers.at(evenNumbers.size() - 1));
            evenDuplications += '\n';
        }
        if(!oddNumbers.empty()) {
            oddDuplications += streetInfo.first->getStreetName() + " " + streetInfo.first->getStreetType() + " : " +
                std::to_string(oddNumbers.at(0)) + "-" + std::to_string(oddNumbers.at(oddNumbers.size() - 1));
            oddDuplications += '\n';
        }
    }
}
void DuplicateFinder::updateDuplicationInfo(std::map<std::unique_ptr<StreetIdentifier>,
                                                     std::unique_ptr<NumberInfo>> &streetMap,
                                            DataStreetInfoMapper::StreetIdInfoPair &newData) {
    for (auto& pair : streetMap) {
        if (*pair.first == *newData.first) {
            pair.second->updateNumberInfo(*newData.second);
            return;
        }
    }
    streetMap.insert(std::move(newData));

}
