//
// Created by User on 2024. 02. 22..
//

#ifndef CPP_NNG_MODEL_STREETIDENTIFIER_H_
#define CPP_NNG_MODEL_STREETIDENTIFIER_H_

#include <string>
class StreetIdentifier {
 public:
  bool operator<(const StreetIdentifier& other) const {
    if (streetName != other.streetName) {
        return streetName < other.streetName;
    }
      return streetType < other.streetType;
  }
  bool operator==(const StreetIdentifier& other) const {
      return other.getStreetName() == streetName && other.getStreetType() == streetType;
  }
  const std::string &getStreetName() const;

  void setStreetName(const std::string &streetName);

  const std::string &getStreetType() const;

  void setStreetType(const std::string &streetType);

 private:
  std::string streetName;
  std::string streetType;
};

#endif //CPP_NNG_MODEL_STREETIDENTIFIER_H_
