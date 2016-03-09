#pragma once

#include <unordered_map>
#include <string>

class Code {
public:
    Code(std::unordered_map<std::string, double> pmfOfSymbols)
        : pmfOfSymbols(pmfOfSymbols) {}
    virtual std::unordered_map<std::string, std::string> getCode() = 0;
    double getAverageCodeLength();
    double getEntropy();
    double getCodeEfficiency();

protected:
    std::unordered_map<std::string, double> pmfOfSymbols;
};