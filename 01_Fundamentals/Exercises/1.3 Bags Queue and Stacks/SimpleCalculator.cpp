#include <string>
#include <iostream>
#include <stack>

int calculate(const std::string str) {
    std::stack<int> value;
    std::stack<char> oper;
    for (int i = 0; i != str.size(); ++i) {
        if (str[i] == '(')
            continue;
        else if (str[i] >= '0' && str[i] <= '9') {
            if (i > 0 && str[i-1] >= '0' && str[i-1] <= '9'){
                int temp = value.top();
                value.pop();
                value.push(temp * 10 + (str[i] - '0'));
            }
            else 
                value.push(str[i] - '0');
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            oper.push(str[i]);
        }
        else if (str[i] == ')') {
            int temp2 = value.top();
            value.pop();
            int temp1 = value.top();
            value.pop();
            if (oper.top() == '+')
                value.push(temp1 + temp2);
            else if (oper.top() == '-')
                value.push(temp1 - temp2);
            else if (oper.top() == '*')
                value.push(temp1 * temp2);
            else if (oper.top() == '/')
                value.push(temp1 / temp2);
            oper.pop();
        }
    }
    return value.top();
}

int main() {
    std::string str;
    std::cout << "Enter an arithmetic operations, "
              << "in which each operator is surrounded by two values within parenthesis, "
              << "like (1 + ((2 + 3) * (4 * 5))):" << std::endl;
    getline(std::cin, str);
    std::cout << "=" << calculate(str) << std::endl;
    return 0;
}