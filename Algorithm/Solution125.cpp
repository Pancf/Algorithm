//
//  Solution125.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution125.hpp"

bool isASCIIChar(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isAlphaOrChar(char ch)
{
    return isASCIIChar(ch) || (ch >= '0' && ch <= '9');
}

bool Solution125::isPalindrome(std::string s)
{
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (!isAlphaOrChar(s[i])) {
            i++;
            continue;
        }
        if (!isAlphaOrChar(s[j])) {
            j--;
            continue;
        }
        if (s[i] == s[j] || (isASCIIChar(s[i]) && isASCIIChar(s[j]) && abs(s[i]-s[j]) == 32)) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}
