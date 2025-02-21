#include <stack>
#include <iostream>
using namespace std;

template <typename T>
bool areStacksEqual(stack<T> s1, stack<T> s2) {
    while (!s1.empty() && !s2.empty()) {
        if (s1.top() != s2.top()) return false;
        s1.pop();
        s2.pop();
    }
    return s1.empty() && s2.empty();
}