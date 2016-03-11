#include "Symbol.hpp"
#include <iostream>

using namespace std;

const string Symbol::MERGE_SEPARATOR = "-";

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

ostream& operator<<(ostream &os, const Symbol &symbol) {
    os << symbol.getSymbol() << " " << symbol.getProbability() << " " << (symbol.isMerged() ? "merged" : "unmerged");
    return os;
}