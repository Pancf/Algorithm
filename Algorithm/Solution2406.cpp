//
//  Solution2406.cpp
//  Algorithm
//
//  Created by focus on 9/15/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution2406.hpp"
#include <algorithm>
#include <queue>

int Solution2406::minGroups(vector<vector<int>> &intervals)
{
  if (intervals.size() == 1) return 1;
  std::sort(intervals.begin(), intervals.end());
  std::priority_queue<int, vector<int>, std::greater<int>> min_heap;
  for (auto& interval : intervals) {
    if (!min_heap.empty() && min_heap.top() < interval[0]) min_heap.pop();
    min_heap.push(interval[1]);
  }
  return static_cast<int>(min_heap.size());
}
