//
//  Solution7.cpp
//  Algorithm
//
//  Created by Pancf on 2020/1/4.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution7.hpp"
#include <cmath>
#include <climits>

int Solution7::reverse(int x) {
    int factor = x >= 0 ? 1 : -1;
    unsigned long a = fabs(x);
    unsigned long rv = 0;
    while (a) {
        auto ele = a % 10;
        rv = rv * 10 + ele;
        a = a / 10;
    }
    if (rv > INT_MAX) {
        return 0;
    } else {
        return (int)rv * factor;
    }
}
