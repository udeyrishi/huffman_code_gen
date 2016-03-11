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

#include "Symbol.hpp"
#include "StringUtils.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

const string Symbol::MERGE_SEPARATOR = "----____----";

Symbol::Symbol(string symbol, double probability, bool merged)
        : symbol(symbol), probability(probability), merged(merged) {
    if (!merged) {
        assertValid(symbol);
    }
}

Symbol Symbol::merge(const Symbol &other) {
    return Symbol(symbol + MERGE_SEPARATOR + other.symbol, probability + other.probability, true);
}

bool Symbol::operator<(const Symbol &other) const {
    return probability < other.probability;
}

bool Symbol::operator>(const Symbol &other) const {
    return probability > other.probability;
}

Symbol& Symbol::operator=(const Symbol &rhs) {
    if (this != &rhs) {
        symbol = rhs.symbol;
        probability = rhs.probability;
        merged = rhs.merged;
    }

    return *this;
}

void Symbol::addBitToSymbolChain(unordered_map<string, string> &codes, int bit) const {
    if (bit > 1 || bit < 0) {
        throw invalid_argument("Bit values can either be 0 or 1.");
    }

    if (isMerged()) {
        for (const string &part : StringUtils::split(getSymbol(), MERGE_SEPARATOR)) {
            codes[part] = to_string(bit) + codes[part];
        }
    }
    else {
        codes[getSymbol()] = to_string(bit);
    }
}

bool Symbol::isValid(const string symbol) {
    return symbol.find(MERGE_SEPARATOR) == string::npos;
}

void Symbol::assertValid(const string symbol) {
    if (!isValid(symbol)) {
        ostringstream exceptionMessage;
        exceptionMessage << "'" << symbol << "' is not an acceptable symbol. ";
        exceptionMessage << "Symbols shouldn't contain '" << MERGE_SEPARATOR << "' substring.";
        throw invalid_argument(exceptionMessage.str());
    }
}

ostream& operator<<(ostream &os, const Symbol &symbol) {
    os << symbol.getSymbol() << " " << symbol.getProbability() << " " << (symbol.isMerged() ? "merged" : "unmerged");
    return os;
}