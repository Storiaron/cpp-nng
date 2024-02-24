//
// Created by User on 2024. 02. 22..
//

#include "NumberInfo.h"


void NumberInfo::updateNumberInfo(const NumberInfo &newInfo) {
    for(auto number : newInfo.numbers) {
        if(!numbers.insert(number).second) {
            duplicateNumbers.insert(number);
        }
    }
}

const std::set<int> &NumberInfo::getDuplicateNumbers() {
    return duplicateNumbers;
}

void NumberInfo::setNumbers(const std::set<int> &numbers) {
    NumberInfo::numbers = numbers;
}
