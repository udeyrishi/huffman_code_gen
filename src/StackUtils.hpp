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

#include <stack>

using namespace std;

// Declaration
class StackUtils {
public:
    template <typename T>
    static T& topAndPop(stack<T> &theStack);

    template <typename T>
    static void sortedInsert(stack<T> &theStack, T &value);
};

// Implementation
template <typename T>
T& StackUtils::topAndPop(stack<T> &theStack) {
    T &top = theStack.top();
    theStack.pop();
    return top;
}

template <typename T>
void StackUtils::sortedInsert(stack<T> &theStack, T &value) {
    if (theStack.empty()) {
        theStack.push(value);
        return;
    }

    T top = theStack.top();
    if (top < value) {
        theStack.pop();
        sortedInsert(theStack, value);
        theStack.push(top);
    }
    else {
        theStack.push(value);
    }
}