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

#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class Symbol {
public:
    Symbol(string symbol, double probability) : Symbol(symbol, probability, false) {}
    Symbol(const Symbol &rhs) : Symbol(rhs.symbol, rhs.probability, rhs.merged) {}

    Symbol merge(const Symbol &other);

    Symbol& operator=(const Symbol &rhs);
    bool operator<(const Symbol &other) const;
    bool operator>(const Symbol &other) const;

    string getSymbol() const { return symbol; }
    double getProbability() const { return probability; }
    bool isMerged() const { return merged; }

    void addBitToSymbolChain(unordered_map<string, string> &codes, int bit);

private:
    Symbol(string symbol, double probability, bool merged)
        : symbol(symbol), probability(probability), merged(merged) {}
    string symbol;
    double probability;
    bool merged;
    static const string MERGE_SEPARATOR;
};

ostream& operator<<(ostream &os, const Symbol &symbol);
