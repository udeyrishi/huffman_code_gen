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

#include "Code.hpp"
#include "Symbol.hpp"
#include <stack>

using namespace std;

class HuffmanCode : public Code {
public:
    HuffmanCode(unordered_map<string, double> pmfOfSymbols);
    unordered_map<string, string> getCode() const;

private:
    stack<Symbol> getSortedSymbolsStack() const;
    void formHuffmanCodes(stack<Symbol> &sortedSymbolsStack,
                          unordered_map<string, string> &codes) const;
};