//
// Created by User on 2024. 02. 22..
//

#include "NumberInfo.h"


std::set<int> NumberInfo::getDuplicateNumbers(const NumberInfo &newInfo) {
    std::set<int> duplications;
    for(auto number : newInfo.numbers) {
        if(!numbers.insert(number).second) {
            duplications.insert(number);
        }
    }
    return duplications;
}

void NumberInfo::setNumbers(const std::set<int> &numbers) {
    NumberInfo::numbers = numbers;
}
