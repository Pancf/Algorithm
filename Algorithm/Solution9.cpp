//
//  Solution9.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/5.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution9.hpp"
#include <cmath>

bool Solution9::isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    unsigned long a = fabs(x);
    unsigned long rv = 0;
    while (a) {
        auto ele = a % 10;
        rv = rv * 10 + ele;
        a = a / 10;
    }
    return (rv == x);
}
