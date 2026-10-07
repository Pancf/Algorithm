//
//  Solution1162.cpp
//  Algorithm
//
//  Created by focus on 10/6/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1162.hpp"
#include <queue>

int Solution1162::maxDistance(vector<vector<int>> &grid)
{
  int length = static_cast<int>(grid.size());
  if (length == 1) return -1;
  
  std::queue<std::pair<int, int>> q;
  
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length; ++j) {
      if (grid[i][j] == 1) {
        q.push({i - 1, j});
        q.push({i, j + 1});
        q.push({i + 1, j});
        q.push({i, j - 1});
      }
    }
  }
  q.push({-2, -2});
  
  int dist = 1;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (i == -2 && j == -2 && !q.empty()) {
      dist++;
      q.push({-2, -2});
      continue;
    }
    if (i >= 0 && i < length && j >= 0 && j < length && grid[i][j] == 0) {
      grid[i][j] = dist;
      q.push({i - 1, j});
      q.push({i, j + 1});
      q.push({i + 1, j});
      q.push({i, j - 1});
    }
  }
  return dist == 1 ? -1 : dist - 1;
}
