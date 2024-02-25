//
// Created by User on 2024. 02. 21..
//

#ifndef CPP_NNG__DUPLICATEFINDER_H_
#define CPP_NNG__DUPLICATEFINDER_H_

#include <vector>
#include <string>
#include <map>
#include <memory>
#include "../model/StreetIdentifier.h"
#include "../model/NumberInfo.h"
#include "../input_processing/DataStreetInfoMapper.h"

class DuplicateFinder {
 public:
  void getNumberDuplications(std::vector<DataStreetInfoMapper::StreetIdInfoPair>& streetInfos,
                             std::string& evenDuplications, std::string& oddDuplications);
 private:
  //method namr that builds streetmap
  void updateDuplicationInfo(std::map<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>& streetMap,
                             DataStreetInfoMapper::StreetIdInfoPair& newData);
  void duplicationInfoToText(std::map<std::unique_ptr<StreetIdentifier>, std::unique_ptr<NumberInfo>>& streetMap,
                                              std::string& evenDuplications, std::string& oddDuplications)
};

#endif //CPP_NNG__DUPLICATEFINDER_H_
