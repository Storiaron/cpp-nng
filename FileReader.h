//
// Created by User on 2024. 02. 21..
//

#ifndef CPP_NNG__FILEREADER_H_
#define CPP_NNG__FILEREADER_H_

#include <string>
class FileReader {
 public:
  void readFile(const std::string& filePath);
 private:
  void readMifFile(const std::string& filePath);
  void readMidFile(const std::string& filePath);
  std::string getFileExtension(const std::string& filePath);
};

#endif //CPP_NNG__FILEREADER_H_
