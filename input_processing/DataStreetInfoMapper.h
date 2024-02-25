//
// Created by User on 2024. 02. 24..
//

#ifndef CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_
#define CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_

#include <string>
#include <map>
#include "../model/NumberInfo.h"
#include "../model/StreetIdentifier.h"
class DataStreetInfoMapper {
 public:
  using StreetIdInfoPair = std::pair<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>;
  std::vector<StreetIdInfoPair> parseData(const std::vector<std::string>& data);
 private:
  std::vector<std::string> splitLine(std::string line, char delimiter);
  StreetIdInfoPair parseLine(const std::string& line);
  std::unique_ptr<StreetIdentifier> buildStreetIdentifier(const std::vector<std::string>& info);
  std::unique_ptr<NumberInfo> buildNumberInfo(const std::vector<std::string>& info);
};
#endif //CPP_NNG_INPUT_OUTPUT_DATASTREETINFOMAPPER_H_
