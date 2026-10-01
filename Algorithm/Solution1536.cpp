//
//  Solution1536.cpp
//  Algorithm
//
//  Created by focus on 9/30/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1536.hpp"
#include <algorithm>

int Solution1536::minSwaps(vector<vector<int>> &grid)
{
  int n = static_cast<int>(grid.size());
  if (n == 1) return grid[0][0] == 1 ? -1 : 0;
  vector<int> trailing0(n, 0);
  for (int i = 0; i < n; ++i) {
    int cnt0 = 0;
    for (int j = n - 1; j >= 0; --j) {
      if (grid[i][j] == 0) cnt0++;
      else break;
    }
    trailing0[i] = cnt0;
  }
  int steps= 0;
  for (int i = 0; i < n; ++i) {
    int needed = n - i - 1;
    int j = i;
    // find first statisfied trailing[j]
    while (j < n && trailing0[j] < needed) j++;
    if (j == n) return -1;
    while (j > i) {
      std::swap(trailing0[j], trailing0[j - 1]);
      j--;
      steps++;
    }
  }
  return steps;
}
