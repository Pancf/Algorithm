//
//  Solution2568.cpp
//  Algorithm
//
//  Created by focus on 10/10/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution2568.hpp"

int Solution2568::minImpossibleOR(std::vector<int> &nums)
{
  /**
   [1] -> [1]
   [1 2] -> [1 2 3]
   [1 2 4] -> [1...7]
   [1 2 4 8] -> [1...15]
   */
  int length = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());
  int e = 0, pos = 0;
  while (true) {
    int key = pow(2, e);
    bool find = false;
    for (; pos < length; ++pos) {
      if (nums[pos] == key) {
        find = true;
        break;
      }
    }
    if (!find) return key;
    e++;
  }
}
