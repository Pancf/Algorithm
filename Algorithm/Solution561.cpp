//
//  Solution561.cpp
//  Algorithm
//
//  Created by focus on 9/11/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution561.hpp"
#include <algorithm>

int Solution561::arrayPairSum(vector<int> &nums)
{
  std::sort(nums.begin(), nums.end());
  int sum = 0;
  for (int i = 0; i < nums.size(); i += 2) {
    sum += nums[i];
  }
  return sum;
}
