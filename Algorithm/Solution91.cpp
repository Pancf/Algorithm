//
//  Solution91.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/9.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution91.hpp"
#include <vector>

/**
 F(n) = the number of ways to decode s.substr(0, n)
 then if s[n].intValue != 0, F(n) += F(n-1), that means s[n] can be decoded solely
 then if s[n-1, n].intValue >= 10 & <= 26, F(n) += F(n-2), that means s[n] can be
 decoded together with previous character
 */
int Solution91::numDecodings(std::string s)
{
    int length = (int)s.size();
    if (length == 0 || s[0] == '0') return 0;
    if (length == 1) return 1;
    int pre1 = 1, pre2 = 1, cur = 0;
    for (int i = 1; i < length; ++i) {
        cur = 0;
        int first = s[i] - '0';
        int second = std::stoi(s.substr(i - 1, 2));
        if (first >= 1 && first <= 9) {
            cur += pre1;
        }
        if (second >= 10 && second <= 26) {
            cur += pre2;
        }
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}
