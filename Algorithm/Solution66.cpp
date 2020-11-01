//
//  Solution66.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution66.hpp"

std::vector<int> Solution66::plusOne(std::vector<int> &digits)
{
    std::vector<int> res(digits.size(), 0);
    bool carryOut = true;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        int sum = digits[i] + (carryOut ? 1 : 0);
        if (sum >= 10) {
            carryOut = true;
            res[i] = 0;
        } else {
            res[i] = sum;
            carryOut = false;
        }
    }
    if (carryOut) res.insert(res.begin(), 1);
    return res;
}
