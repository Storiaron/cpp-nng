//
// Created by User on 2024. 02. 22..
//

#ifndef CPP_NNG_MODEL_NUMBERINFO_H_
#define CPP_NNG_MODEL_NUMBERINFO_H_

#include <string>
#include <vector>
#include <memory>
#include <set>

class NumberInfo {
 public:

  std::set<int> getDuplicateNumbers(const NumberInfo &newInfo);

  void setNumbers(const std::set<int> &numbers);

 private:
  std::set<int> numbers;
};

#endif //CPP_NNG_MODEL_NUMBERINFO_H_
