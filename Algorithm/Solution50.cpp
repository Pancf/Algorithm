//
//  Solution50.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution50.hpp"
#include <stdlib.h>

//        /- (x^2)^(n/2) if n % 2 == 0
//       /
// x^n =
//       \
//        \- x * (x^2)^(n/2) if n % 2 == 1
double Solution50::myPow(double x, int n)
{
    double res = 1;
    // absN must be `unsigned` type, otherwise may be overflow
    unsigned absN;
    if (n < 0) {
        x = 1 / x;
        absN = abs(n);
    } else {
        absN = n;
    }
    while (absN) {
        if (absN & 1) {
            res *= x;
        }
        x = x * x;
        absN = absN >> 1;
    }
    return res;
}
