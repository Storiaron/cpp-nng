//
// Created by User on 2024. 02. 21..
//

#ifndef CPP_NNG_FILEREADER_H_
#define CPP_NNG_FILEREADER_H_

#include <string>
#include <vector>
class FileReader {
 public:
  std::vector<std::string> readFile(const std::string& filePath);
 private:
  std::vector<std::string> readMidFile(const std::string& filePath);
  std::string getFileExtension(const std::string& filePath);
};

#endif //CPP_NNG_FILEREADER_H_
