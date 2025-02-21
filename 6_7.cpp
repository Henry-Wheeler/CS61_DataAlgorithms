// Problem 7: Evaluate Boolean Expressions
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

bool evaluateBooleanExpression(const std::string& expr);
bool performOperation(bool left, bool right, char op);
bool performComparison(int left, int right, const std::string& comp);

int main() {
    std::string input;
    std::cout << "Enter a fully parenthesized boolean expression: \n";
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") break;
        try {
            bool result = evaluateBooleanExpression(input);
            std::cout << "Result: " << (result ? "true" : "false") << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
        std::cout << "Enter another expression (or type 'exit' to quit): \n";
    }
    return 0;
}

bool evaluateBooleanExpression(const std::string& expr) {
    std::stack<bool> operands;
    std::stack<char> operators;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token == "(") {
            continue;
        } else if (token == "&&" || token == "||" || token == "!" || token == "<" || token == ">" || token == "<=" || token == ">=" || token == "==" || token == "!=") {
            operators.push(token[0]);
        } else if (std::isdigit(token[0])) {
            operands.push(std::stoi(token));
        } else if (token == ")") {
            if (operators.empty()) throw std::runtime_error("Malformed expression");
            char op = operators.top(); operators.pop();

            if (op == '!') {
                if (operands.empty()) throw std::runtime_error("Malformed expression");
                bool val = operands.top(); operands.pop();
                operands.push(!val);
            } else {
                if (operands.size() < 2) throw std::runtime_error("Malformed expression");
                bool right = operands.top(); operands.pop();
                bool left = operands.top(); operands.pop();
                operands.push(performOperation(left, right, op));
            }
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (operands.size() != 1) throw std::runtime_error("Malformed expression");
    return operands.top();
}

bool performOperation(bool left, bool right, char op) {
    switch (op) {
        case '&&': return left && right;
        case '||': return left || right;
        default: throw std::runtime_error("Unsupported operator");
    }
}
