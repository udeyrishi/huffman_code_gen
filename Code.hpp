#pragma once

#include <unordered_map>
#include <string>

using namespace std;

class Code {
public:
    Code(unordered_map<string, double> pmfOfSymbols);
    virtual unordered_map<string, string> getCode() = 0;
    double getAverageCodeLength();
    double getEntropy();
    double getCodeEfficiency();

protected:
    unordered_map<string, double> pmfOfSymbols;
};