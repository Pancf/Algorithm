//
//  Solution70.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution70.hpp"

int Solution70::climbStairs(int n)
{
    // f(n) means the number of ways climbing n stairs
    // then f(n) = f(n-1) + f(n-2)
    if (n == 1 || n == 2) return n;
    int p1 = 1, p2 = 2;
    for (int i = 3; i <= n; ++i) {
        auto temp = p2;
        p2 = p1 + p2;
        p1 = temp;
    }
    return p2;
}
