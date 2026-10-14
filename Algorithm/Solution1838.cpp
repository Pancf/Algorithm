//
//  Solution1838.cpp
//  Algorithm
//
//  Created by focus on 10/12/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1838.hpp"

int Solution1838::maxFrequency(std::vector<int>& nums, int k)
{
  std::sort(nums.begin(), nums.end());
  
  /** First solution. Nested for-loop is redundant.
  int res = INT_MIN;
  int i = static_cast<int>(nums.size() - 1);
  while (i > 0) {
    int budget = k;
    int freq = 1;
    for (int j = i - 1; j >= 0; --j) {
      if (nums[j] == nums[i]) {
        freq++;
        i--;
      } else if (nums[j] + budget >= nums[i]) {
        budget -= (nums[i] - nums[j]);
        freq++;
      } else {
        break;
      }
    }
    res = std::max(res, freq);
    i--;
  }
  return res;
  */
  int l = 0, res = 1;
  long sum = 0; // avoid integer overflow
  for (int r = 0; r < nums.size(); ++r) {
    sum += nums[r];
    while (static_cast<long>(r - l + 1) * nums[r] - sum > k) {
      sum -= nums[l];
      l++;
    }
    res = std::max(res, r - l + 1);
  }
  return res;
}
