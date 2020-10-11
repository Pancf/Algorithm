//
//  Solution20.cpp
//  Algorithm
//
//  Created by Pancf on 2020/8/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution20.hpp"
#include <stack>

using std::stack;

bool Solution20::isValid(string s)
{
    if (s.size() == 0) return true;
    if (s.size() == 1) return false;
    std::stack<char> st;
    st.push(s[0]);
    bool shouldContinue = true;
    for (int i = 1; i < s.size(); ++i) {
        char c = s[i];
        switch (c) {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;
            case ')':
                if (!st.empty() && '(' == st.top()) {
                    st.pop();
                } else {
                    shouldContinue = false;
                }
                break;
            case ']':
                if (!st.empty() && '[' == st.top()) {
                    st.pop();
                } else {
                    shouldContinue = false;
                }
                break;
            case '}':
                if (!st.empty() && '{' == st.top()) {
                    st.pop();
                } else {
                    shouldContinue = false;
                }
                break;
        }
        if (!shouldContinue) {
            break;
        }
    }
    return st.empty() && shouldContinue;
}
