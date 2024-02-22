//
// Created by User on 2024. 02. 22..
//

#ifndef CPP_NNG_MODEL_STREETIDENTIFIER_H_
#define CPP_NNG_MODEL_STREETIDENTIFIER_H_

#include <string>
class StreetIdentifier {
 public:
  bool operator<(const StreetIdentifier& other) const {
    if (streetName != other.streetName)
      return streetName < other.streetName;
    if (streetType != other.streetType)
      return streetType < other.streetType;
    if (postalCodeLeftSide != other.postalCodeLeftSide)
      return postalCodeLeftSide < other.postalCodeLeftSide;
    return postalCodeRightSide < other.postalCodeRightSide;
  }
 private:
  std::string streetName;
  std::string streetType;
  std::string postalCodeLeftSide;
  std::string postalCodeRightSide;
};

#endif //CPP_NNG_MODEL_STREETIDENTIFIER_H_
