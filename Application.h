//
// Created by User on 2024. 02. 25..
//

#ifndef CPP_NNG_APPLICATION_H_
#define CPP_NNG_APPLICATION_H_


#include "input_processing/DataStreetInfoMapper.h"
#include "output_handling/Logger.h"
#include "input_processing/FileReader.h"
#include "logic/DuplicateFinder.h"

class Application {
 public:
  Application(DataStreetInfoMapper dataStreetInfoMapper, FileReader fileReader, Logger logger, DuplicateFinder duplicateFinder) :
      dataStreetInfoMapper(dataStreetInfoMapper), fileReader(fileReader), logger(logger), duplicateFinder(duplicateFinder){};
  void run(const std::string& inputFilePath);
 private:
  DataStreetInfoMapper dataStreetInfoMapper;
  FileReader fileReader;
  Logger logger;
  DuplicateFinder duplicateFinder;
};


#endif //CPP_NNG__APPLICATION_H_
