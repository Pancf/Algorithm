//
//  Solution69.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution69.hpp"
#include <math.h>

int Solution69::mySqrt(int x)
{
    // because maxX = 2^31 - 1, maxX * maxX < 2^31 * 2^31 = 2^62 < 2*31 - 1 = LONG_MAX
    long long guess = x;
    while (guess * guess > x) {
        guess = (guess + x / guess) / 2;
    }
    return (int)guess;
}
