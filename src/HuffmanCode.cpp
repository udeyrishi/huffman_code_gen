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

#include "HuffmanCode.hpp"
#include "StackUtils.hpp"
#include "StringUtils.hpp"
#include <algorithm>
#include <vector>

using namespace std;

stack<Symbol> HuffmanCode::getSortedSymbolsStack() const {
    vector<Symbol> sortedSymbols;
    for (const pair<string, double> &symbol : pmfOfSymbols) {
        sortedSymbols.push_back(Symbol(symbol.first, symbol.second));
    }

    sort(sortedSymbols.begin(), sortedSymbols.end());

    stack<Symbol> sortedSymbolsStack;
    for_each(sortedSymbols.rbegin(),
             sortedSymbols.rend(),
             [&](Symbol symbol) {
                 sortedSymbolsStack.push(symbol);
             });

    return sortedSymbolsStack;
}

unordered_map<string, string> HuffmanCode::getCode() const {
    unordered_map<string, string> codes;
    stack<Symbol> symbols = getSortedSymbolsStack();

    switch (symbols.size()) {
        case 0:
            break;

        case 1:
            codes[StackUtils::topAndPop(symbols).getSymbol()] = "0";
            break;

        default:
            formHuffmanCodes(symbols, codes);
            break;
    }
    return codes;
}

void HuffmanCode::formHuffmanCodes(stack<Symbol> &sortedSymbolsStack,
                                   unordered_map<string, string> &resultCodes) const {

    if (sortedSymbolsStack.size() < 2) {
        throw invalid_argument("Need at least 2 symbols to form the Huffman Code");
    }

    while (sortedSymbolsStack.size() > 1) {
        Symbol first = StackUtils::topAndPop(sortedSymbolsStack);
        Symbol second = StackUtils::topAndPop(sortedSymbolsStack);
        Symbol merged = first.merge(second);

        if (first.isMerged()) {
            for (const string &part : StringUtils::split(first.getSymbol(), Symbol::MERGE_SEPARATOR)) {
                resultCodes[part] = "0" + resultCodes[part];
            }
        }
        else {
            resultCodes[first.getSymbol()] = "0";
        }

        if (second.isMerged()) {
            for (const string &part : StringUtils::split(second.getSymbol(), Symbol::MERGE_SEPARATOR)) {
                resultCodes[part] = "1" + resultCodes[part];
            }
        }
        else {
            resultCodes[second.getSymbol()] = "1";
        }

        StackUtils::sortedInsert(sortedSymbolsStack, merged);
    }
}