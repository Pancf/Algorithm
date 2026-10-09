//
//  Solution1636.cpp
//  Algorithm
//
//  Created by focus on 10/9/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1636.hpp"
#include <unordered_map>

std::vector<int> Solution1636::frequencySort(std::vector<int> &nums)
{
  /** first version, too complex
  int length = static_cast<int>(nums.size());
  if (length == 1) return nums;
  
  std::unordered_map<int, int> m;
  for (auto num : nums) {
    m[num] += 1;
  }
  
  std::vector<std::pair<int, int>> vec;
  for (auto [k, v] : m) {
    vec.push_back({k, v});
  }
  std::sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) {
    if (lhs.second < rhs.second) return true;
    if (lhs.second == rhs.second) return lhs.first > rhs.first;
    return false;
  });
  
  std::vector<int> res;
  for (auto [value, freq] : vec) {
    while (freq--) {
      res.push_back(value);
    }
  }
  return res;
  */
  // problem constraint, -100 <= nums[i] <= 100
  int freq[201] = {0};
  for (int num : nums) {
    freq[num + 100] += 1;
  }
  std::sort(nums.begin(), nums.end(), [&freq](auto& lhs, auto& rhs) {
    if (freq[lhs + 100] == freq[rhs + 100]) return lhs > rhs;
    return freq[lhs + 100] < freq[rhs + 100];
  });
  return nums;
}
