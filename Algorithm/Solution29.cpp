//
//  Solution29.cpp
//  Algorithm
//
//  Created by Pancf on 2019/11/26.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution29.hpp"
#include <iostream>


int Solution29::divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return (int)(sign * ans);
}
