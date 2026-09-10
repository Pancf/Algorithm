//
//  Solution1984.cpp
//  Algorithm
//
//  Created by focus on 9/10/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1984.hpp"
#include <algorithm>

int Solution1984::minimumDifference(vector<int>& nums, int k)
{
  if (nums.size() == 1) return 0;
  assert(nums.size() >= k);
  int diff = INT_MAX;
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i <= nums.size() - k; ++i) {
    diff = std::min(nums[i+k-1] - nums[i], diff);
  }
  return diff;
}
