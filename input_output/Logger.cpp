//
// Created by User on 2024. 02. 23..
//

#include "Logger.h"

void Logger::logResults(const std::vector<std::string>& results) {
    for(const auto& result : results) {
        std::cout<< result << std::endl;
    }
}
