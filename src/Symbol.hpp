#pragma once

#include <string>

using namespace std;

class Symbol {
public:
    static const string MERGE_SEPARATOR;

    Symbol(string symbol, double probability) : Symbol(symbol, probability, false) {}
    Symbol(const Symbol &rhs) : Symbol(rhs.symbol, rhs.probability, rhs.merged) {}

    Symbol merge(const Symbol &other);

    Symbol& operator=(const Symbol &rhs);
    bool operator<(const Symbol &other) const;
    bool operator>(const Symbol &other) const;

    string getSymbol() const { return symbol; }
    double getProbability() const { return probability; }
    bool isMerged() const { return merged; }

private:
    Symbol(string symbol, double probability, bool merged)
        : symbol(symbol), probability(probability), merged(merged) {}
    string symbol;
    double probability;
    bool merged;
};

ostream& operator<<(ostream &os, const Symbol &symbol);
