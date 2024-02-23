//
// Created by User on 2024. 02. 21..
//

#ifndef CPP_NNG__DATAPARSER_H_
#define CPP_NNG__DATAPARSER_H_

#include <vector>
#include <string>
#include <map>
#include <memory>
#include "model/StreetIdentifier.h"
#include "model/NumberInfo.h"
//TODO rename these aliases

using StreetIdInfoPair = std::pair<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>;
using StreetMap = std::map<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>;
class DataParser {
 public:
  std::vector<std::string> parseData(const std::vector<std::string>& data);
 private:
  StreetIdInfoPair parseLine(const std::string& line);
  std::pair<std::string, std::set<int>> getDuplicationInfo(StreetMap& streetInfo,
                                                      StreetIdInfoPair data);
  std::vector<std::string> splitLine(std::string line, char delimiter);
  std::unique_ptr<StreetIdentifier> buildStreetIdentifier(std::vector<std::string> info);
  std::unique_ptr<NumberInfo> buildNumberInfo(std::vector<std::string> info);
  void duplicationInfoToText(std::pair<std::string, std::set<int>> duplicationInfo, std::string& evenDuplications, std::string& oddDuplications);
};

#endif //CPP_NNG__DATAPARSER_H_
