//
//  Solution78.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/7.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution78.hpp"

std::vector<std::vector<int>> Solution78::subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res{{}};
    if (nums.size() == 0) return res;
    int count = pow(2, nums.size());
    for (int i = 1; i < count; ++i) {
        // 001 -> 111
        int index = 0, tmp = i;
        std::vector<int> v;
        while (tmp) {
            if (tmp & 0x1) {
                v.push_back(nums[index]);
            }
            index++;
            tmp = tmp >> 1;
        }
        res.push_back(v);
    }
    return res;
}
