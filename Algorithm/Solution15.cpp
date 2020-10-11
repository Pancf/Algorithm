//
//  Solution15.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution15.hpp"
#include <algorithm>

std::vector<std::vector<int>> Solution15::threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> res;
    if (nums.size() < 3) return res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; ++i) {
        int sum = 0 - nums[i];
        int low = i + 1;
        int high = nums.size() - 1;
        while (low < high) {
            if (sum == nums[low] + nums[high]) {
                res.push_back({nums[i], nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1]) ++low;
                while (low < high && nums[high] == nums[high - 1]) --high;
                ++low;
                --high;
            } else if (sum > nums[low] + nums[high]) {
                ++low;
            } else {
                --high;
            }
        }
        while (nums[i] == nums[i + 1] && i < nums.size() - 2) ++i;
        
    }
    return res;
}
