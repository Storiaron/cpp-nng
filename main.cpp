#include <iostream>
#include "input_output/FileReader.h"
#include "DataParser.h"
#include "input_output/Logger.h"

int main() {
  FileReader fileReader;
  DataParser dataParser;
  Logger logger;
  std::locale::global(std::locale("hu_HU.UTF-8"));
  std::vector<std::string> data = fileReader.readFile("../task/network.mid");
  logger.logResults(dataParser.parseData(data));
  return 0;
}
