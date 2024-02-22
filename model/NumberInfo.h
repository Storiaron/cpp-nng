//
// Created by User on 2024. 02. 22..
//

#ifndef CPP_NNG_MODEL_NUMBERINFO_H_
#define CPP_NNG_MODEL_NUMBERINFO_H_

#include <string>
class NumberInfo {
 public:
  std::string updateNumberInfo(std::string numberingScheme, std::string side,
                               int startingNumber, int endingNumber);
 private:
  std::string numberingSchemeLeftSide;
  std::string numberingSchemeRightSide;
  int startingNumberLeftSide;
  int endingNumberLeftSide;
  int startingNumberRightSide;
  int endingNumberRightSide;
};

#endif //CPP_NNG_MODEL_NUMBERINFO_H_
