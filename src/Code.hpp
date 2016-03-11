#pragma once

#include <unordered_map>
#include <string>

using namespace std;

class Code {
public:
    Code(unordered_map<string, double> pmfOfSymbols);
    virtual unordered_map<string, string> getCode() const = 0;
    double getAverageCodeLength() const;
    double getEntropy() const;
    double getEfficiency() const;

protected:
    unordered_map<string, double> pmfOfSymbols;
};

ostream& operator<<(ostream &os, const Code &code);