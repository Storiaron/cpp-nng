//
// Created by User on 2024. 02. 21..
//

#ifndef CPP_NNG__DATAPARSER_H_
#define CPP_NNG__DATAPARSER_H_

#include <vector>
#include <string>
#include <map>
#include "model/StreetIdentifier.h"
#include "model/NumberInfo.h"
class DataParser {
 public:
  std::vector<std::string> parseData(std::vector<std::string> data);
 private:
  std::pair<StreetIdentifier, NumberInfo> parseLine(std::string line);
  std::string updateStreetInfo(std::map<StreetIdentifier, NumberInfo>& streetInfo,
                               std::pair<StreetIdentifier, NumberInfo>);
};

#endif //CPP_NNG__DATAPARSER_H_
