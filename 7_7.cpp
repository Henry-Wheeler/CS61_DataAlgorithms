#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool evaluateBooleanExpression(const string& expr) {
    stack<bool> operands;
    stack<char> operators;
    for (size_t i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        if (ch == '(') {
            continue;
        } else if (ch == '&' || ch == '|' || ch == '!') {
            operators.push(ch);
        } else if (ch == '<' || ch == '>' || ch == '=' || ch == '!') {
            operators.push(ch);
        } else if (ch >= '0' && ch <= '9') {
            int number = 0;
            while (i < expr.length() && expr[i] >= '0' && expr[i] <= '9') {
                number = number * 10 + (expr[i] - '0');
                ++i;
            }
            --i; 
            operands.push(number);
        } else if (ch == ')') {
            char op = operators.top(); operators.pop();

            if (op == '!') {
                bool val = operands.top(); operands.pop();
                operands.push(!val);
            } else {
                bool right = operands.top(); operands.pop();
                bool left = operands.top(); operands.pop();
                operands.push(performOperation(left, right, op));
            }
        }
    }
    return operands.top();
}

bool performOperation(bool left, bool right, char op) {
    switch (op) {
        case '&': return left && right;
        case '|': return left || right;
        default: return false;
    }
}