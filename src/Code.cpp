#include "Code.hpp"
#include <math.h>
#include <limits>
#include <iostream>

using namespace std;

Code::Code(unordered_map<string, double> pmfOfSymbols) : pmfOfSymbols(pmfOfSymbols) {
    // TODO: check probability sums to 1
}

double Code::getAverageCodeLength() const {
    double averageCodeLength = 0;
    int codeLength;
    double probability;

    for (auto const &symbol : getCode()) {
        codeLength = symbol.second.length();
        probability = pmfOfSymbols.at(symbol.first);
        averageCodeLength +=  static_cast<double>(codeLength) * probability;
    }

    return averageCodeLength;
}

double Code::getEntropy() const {
    double entropy = 0.0;
    double probability;

    for (auto const &symbol : pmfOfSymbols) {
        probability = symbol.second;
        entropy -= probability * log2(probability);
    }
    return entropy;
}

double Code::getEfficiency() const {
    double averageCodeLength = getAverageCodeLength();

    if (averageCodeLength == 0.0) {
        return numeric_limits<float>::infinity();
    }
    return getEntropy()/averageCodeLength;
}

ostream& operator<<(ostream &os, const Code &code) {
    unordered_map<string, string> _code = code.getCode();

    os << "Huffman Code: " << endl;
    for (const auto &c : _code) {
        os << "(" << c.first << "," << c.second << ") " << endl;
    }

    os << "Average code length: " << code.getAverageCodeLength() << endl;
    os << "Entropy: " << code.getEntropy() << endl;
    os << "Efficiency: " << code.getEfficiency() * 100 << "\%" << endl;

    return os;
}