//
// Created by User on 2024. 02. 21..
//

#include <fstream>
#include <iostream>
#include <stack>
#include "FileReader.h"
void FileReader::readFile(const std::string &filePath) {
  std::string extension = getFileExtension(filePath);
  if(extension == "mif") {
    readMifFile(filePath);
  }
  else if(extension == "mid") {
    readMidFile(filePath);
  }
  else {
    std::cerr << "You entered a currently unsupported file format" << std::endl;
  }
}
void FileReader::readMifFile(const std::string& filePath) {
  std::ifstream file(filePath);
  if (file.is_open()) {
    std::string line;
    bool isDataSection = false;

    // Skip header section
    while (std::getline(file, line)) {
      if (line.find("Data") != std::string::npos) {
        isDataSection = true;
        break;
      }
    }
    while (std::getline(file, line)) {
      if (line.empty()) // Skip empty lines
        continue;
      std::cout << line << std::endl;
    }

    file.close();
  } else {
    std::cerr << "Unable to open file: " << filePath << std::endl;
  }
}
void FileReader::readMidFile(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open the file." << std::endl;
  }
  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }
  file.close();
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
