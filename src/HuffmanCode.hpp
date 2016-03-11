#pragma once

#include "Code.hpp"
#include "Symbol.hpp"
#include <stack>

using namespace std;

class HuffmanCode : public Code {
public:
    HuffmanCode(unordered_map<string, double> pmfOfSymbols) : Code(pmfOfSymbols) {}
    unordered_map<string, string> getCode() const;

private:
    stack<Symbol> getSortedSymbolsStack() const;
    void formHuffmanCodes(stack<Symbol> &sortedSymbolsStack,
                          unordered_map<string, string> &codes) const;
};