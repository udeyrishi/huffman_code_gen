#include "Code.hpp"
#include <math.h>
#include <limits>

using namespace std;

Code::Code(unordered_map<string, double> pmfOfSymbols) : pmfOfSymbols(pmfOfSymbols) {
    // TODO: check probability sums to 1
}

double Code::getAverageCodeLength() {
    double averageCodeLength = 0;
    int codeLength;
    double probability;

    for (auto const &symbol : getCode()) {
        codeLength = symbol.second.length();
        probability = pmfOfSymbols[symbol.first];
        averageCodeLength +=  static_cast<double>(codeLength) * probability;
    }

    return averageCodeLength;
}

double Code::getEntropy() {
    double entropy = 0.0;
    double probability;

    for (auto const &symbol : pmfOfSymbols) {
        probability = symbol.second;
        entropy -= probability * log2(probability);
    }
    return entropy;
}

double Code::getCodeEfficiency() {
    double averageCodeLength = getAverageCodeLength();

    if (averageCodeLength == 0.0) {
        return numeric_limits<float>::infinity();
    }
    return getEntropy()/averageCodeLength;
}