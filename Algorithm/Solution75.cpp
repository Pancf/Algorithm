//
//  Solution75.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution75.hpp"

void Solution75::sortColors(std::vector<int> &nums)
{
    int numOfZero = 0, numOfOne = 0, numOfTwo = 0;
    for (auto num : nums) {
        if (num == 0) numOfZero++;
        else if (num == 1) numOfOne++;
        else if (num == 2) numOfTwo++;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i < numOfZero) nums[i] = 0;
        else if (i < numOfOne + numOfZero) nums[i] = 1;
        else nums[i] = 2;
    }
}
