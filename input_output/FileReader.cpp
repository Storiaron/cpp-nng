//
// Created by User on 2024. 02. 21..
//

#include <fstream>
#include <iostream>
#include <stack>
#include "FileReader.h"
std::vector<std::string> FileReader::readFile(const std::string &filePath) {
  std::string extension = getFileExtension(filePath);
  if(extension == "mid") {
    return readMidFile(filePath);
  }
  else {
    std::cerr << "You entered a currently unsupported file format" << std::endl;
  }
}
std::vector<std::string> FileReader::readMidFile(const std::string& filePath) {
  std::ifstream file(filePath);
  std::vector<std::string> fileData;
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open the file." << std::endl;
  }
  std::string line;
  while (std::getline(file, line)) {
    //TODO remove cout after development
    //std::cout << line << std::endl;
    fileData.push_back(line);
  }
  file.close();
  return fileData;
}
std::string FileReader::getFileExtension(const std::string& filePath) {
  std::string extension = "";
  std::stack<char> postDotChars;
  for(int i = filePath.size() - 1; i >=0; i--) {
    if(filePath.at(i) == '.') {
      break;
    }
    else {
      postDotChars.push(filePath.at(i));
    }
  }
  while(!postDotChars.empty()) {
    extension += postDotChars.top();
    postDotChars.pop();
  }
  return extension;
}
