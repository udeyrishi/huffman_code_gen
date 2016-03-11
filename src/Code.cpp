/**
 Copyright 2016 Udey Rishi
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "Code.hpp"
#include <math.h>
#include <limits>
#include <iostream>

using namespace std;

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
    os << "Efficiency: " << code.getEfficiency() * 100 << "%" << endl;

    return os;
}