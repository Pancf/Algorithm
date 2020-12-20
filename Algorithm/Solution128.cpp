//
//  Solution128.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution128.hpp"
#include <unordered_map>
#include <algorithm>

int Solution128::longestConsecutive(std::vector<int> &nums)
{
    if (!nums.size()) return 0;
    int size = (int)nums.size();
    std::unordered_map<int, int> mp; // key is nums[i], value is the length of sequence to which key belongs
    int res = 0;
    for (int i = 0; i < size; ++i) {
        auto key = nums[i];
        if (mp.find(key) == mp.end()) {
            int left = mp.find(key - 1) != mp.end() ? mp[key - 1] : 0; // left neighbor has `left` length
            int right = mp.find(key + 1) != mp.end() ? mp[key + 1] : 0; // right neighbor has `right` length
            int sum = left + right + 1;
            res = std::max(sum, res);
            mp[key] = sum;
            // Why only update mp[key - left] and mp[key + right]?
            // Because only mp[key - left] and mp[key + right] has the possibility to calculate new sum
            mp[key - left] = sum;
            mp[key + right] = sum;
        }
    }
    return res;
}
