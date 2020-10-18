//
//  Solution41.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/18.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution41.hpp"

int Solution41::firstMissingPositive(std::vector<int> &nums)
{
    // nums.size() <= 300, -2^31 <= nums[i] <= 2^31 - 1
    // 要求时间复杂度为o(n)，空间复杂度为常量，也就是说只能遍历一次nums
    // 如何保存遍历过的元素信息是关键
    // 因为nums.size() <= 300，因此第一个缺失的正整数一定 <= 301
    uint32_t fields[10] = {0}; // can store 320 elements info
    for (auto num : nums) {
        if (0 < num && num < 301) {
            // store 1~32 in filed[0], 33~64 in field[1], 65~96 in field[2]
            int index = (num - 1) / 32;
            int shift = (num - 1) % 32;
            fields[index] = fields[index] | (1 << shift);
        }
    }
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        // field[i] contains 0 in some bit
        if (fields[i] ^ 0xFFFFFFFF) {
            index = i;
            break;
        }
    }
    int res = index * 32;
    auto field = fields[index];
    index = 1;
    // find 0 in field
    while (field & 0x1) {
        ++index;
        field = field >> 1;
    }
    res += index;
    return res;
}
