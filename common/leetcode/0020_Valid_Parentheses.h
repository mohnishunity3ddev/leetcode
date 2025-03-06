#pragma once

#include <string>
#include <stack>
#include <iostream>

bool isValid(const std::string& s) {
    std::stack<char> cstack;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            cstack.push(c);
        } else {
            if (cstack.empty()) return false;
            if ((c == ')' && cstack.top() != '(') ||
                (c == '}' && cstack.top() != '{') ||
                (c == ']' && cstack.top() != '['))
            {
                return false;
            } else {
                cstack.pop();
            }
        }
    }
    
    return cstack.empty();
}

void driver() {
    std::string s = "(]";
    bool valid = isValid(s);
    std::cout << s << " is " << valid << std::endl;
}