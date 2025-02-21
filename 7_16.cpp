#include <stack>
#include <iostream>
using namespace std;

template <typename T>
void flipStack(stack<T>& s) {
    stack<T> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    s.swap(temp);
}
