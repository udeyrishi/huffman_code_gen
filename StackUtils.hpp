#pragma once

#include <stack>

using namespace std;

// Declaration
class StackUtils {
public:
    template <typename T>
    static T topAndPop(stack<T> &theStack);
};

// Implementation
template <typename T>
T StackUtils::topAndPop(stack<T> &theStack) {
    T top = theStack.top();
    theStack.pop();
    return top;
}