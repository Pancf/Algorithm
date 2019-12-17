//
//  Solution26.cpp
//  Algorithm
//
//  Created by Pancf on 2019/11/24.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution26.hpp"


int Solution26::removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return (int)nums.size();
    } else if (nums.size() == 2) {
        return (nums[0] == nums[1] ? 1 : 2);
    }
    size_t i = 0;
    for (size_t j = 1; j < nums.size(); ++j) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
            /**
            slower solution
            for (size_t k = i+1; k < j; ++k) {
                nums[k] = nums[j];
            }
            ++i;
            */
        }
    }
    return (int)(i + 1);
}
