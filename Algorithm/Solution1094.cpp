//
//  Solution1094.cpp
//  Algorithm
//
//  Created by focus on 10/8/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1094.hpp"
#include <queue>

bool Solution1094::carPooling(vector<vector<int>> &trips, int capacity)
{
  /** First Intuition
  std::sort(trips.begin(), trips.end(), [](auto& lhs, auto& rhs) {
    int from1 = lhs[1], to1 = lhs[2];
    int from2 = rhs[1], to2 = rhs[2];
    if (from1 < from2) return true;
    if (from1 == from2) return to1 < to2;
    return false;
  });
  auto comp = [](vector<int>& lhs, vector<int>& rhs) {
    return lhs[2] > rhs[2];
  };
  std::priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> onboard;
  
  for (auto& trip : trips) {
    int passengers = trip[0], from = trip[1];
    while (!onboard.empty()) {
      auto offboard = onboard.top();
      if (offboard[2] <= from) {
        capacity += offboard[0];
        onboard.pop();
      } else {
        break;
      }
    }
    capacity -= passengers;
    onboard.push(trip);
    if (capacity < 0) return false;
  }
  return true;
  */
  // 1001 comes from problem constraints
  int stops[1001] = {0};
  for (auto& trip : trips) {
    int passengers = trip[0], from = trip[1], to = trip[2];
    stops[from] += passengers;
    stops[to] -= passengers;
  }
  for (int i = 0; i < 1001; ++i) {
    capacity -= stops[i];
    if (capacity < 0) return false;
  }
  return true;
}
