//
//  Solution53.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/18.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution53.hpp"

int Solution53::maxSubArray(std::vector<int>& nums)
{
    if (nums.size() == 0) return 0;
    // 设maxSoFar[i]表示长度为i+1的数组的最大子数组和，则最终的maxSoFar[nums.length - 1]就是解
    // maxSoFar[i]的取值有两种情况，子数组要么不包含nums[i]这个元素，要么是maxEndingHere,
    // 即maxSoFar[i] = max(maxSoFar[i-1], maxEndingHere[i])
    // maxEndingHere[i]表示以nums[i]为右边界的子数组
    // maxEndingHere[i]的取值又分为两种情况，要么是nums[i]，要么是maxEndingHere[i-1]+nums[i]
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        maxEndingHere = std::max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
