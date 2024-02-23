//
// Created by User on 2024. 02. 22..
//

#include "StreetIdentifier.h"

const std::string &StreetIdentifier::getStreetName() const {
    return streetName;
}

void StreetIdentifier::setStreetName(const std::string &streetName) {
    StreetIdentifier::streetName = streetName;
}

const std::string &StreetIdentifier::getStreetType() const {
    return streetType;
}

void StreetIdentifier::setStreetType(const std::string &streetType) {
    StreetIdentifier::streetType = streetType;
}
