//
//  Solution38.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution38.hpp"

std::string Solution38::countAndSay(int n)
{
    if (n == 1) return "1";
    auto before = countAndSay(n - 1);
    std::string res = "";
    char ch = before[0];
    int num = 0;
    for (int i = 0; i < before.size(); ++i) {
        if (ch == before[i]) {
            ++num;
        } else {
            res = res + std::to_string(num) + ch;
            num = 1;
            ch = before[i];
        }
    }
    if (num != 0) res = res + std::to_string(num) + ch;
    return res;
}
