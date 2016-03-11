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