#include <iostream>
#include "FileReader.h"
#include "DataParser.h"

int main() {
  FileReader fileReader;
  DataParser dataParser;
  std::locale::global(std::locale("hu_HU.UTF-8"));
  std::vector<std::string> data = fileReader.readFile("../task/network.mid");
  dataParser.parseData(data);
  return 0;
}
