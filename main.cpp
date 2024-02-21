#include <iostream>
#include "FileReader.h"

int main() {
  FileReader fileReader;
  std::locale::global(std::locale("hu_HU.UTF-8"));
  fileReader.readFile("../task/network.mid");
  return 0;
}
