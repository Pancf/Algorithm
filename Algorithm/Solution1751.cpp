//
//  Solution1751.cpp
//  Algorithm
//
//  Created by focus on 9/17/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1751.hpp"
#include <algorithm>

int Solution1751::maxValue(vector<vector<int>> &events, int k)
{
  int num_of_events = static_cast<int>(events.size());
  std::sort(events.begin(), events.end(), [](auto& lhs, auto& rhs) {
    if (lhs[1] < rhs[1]) return true;
    if (lhs[1] == rhs[1] && lhs[0] < rhs[0]) return true;
    return false;
  }); // sort by end day
  
  vector<int> end_days;
  for (auto& event : events) {
    end_days.push_back(event[1]);
  }
  
  vector<int> nearest_event;
  for (auto& event : events) {
    // find first end_day >= event.start_day
    auto iter = std::lower_bound(end_days.begin(), end_days.end(), event[0]);
    int i = static_cast<int>(iter - end_days.begin());
    nearest_event.push_back(i);
  }
  
  vector<vector<int>> dp(k + 1, vector<int>(num_of_events + 1, 0));
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= num_of_events; ++j) {
      int pos = nearest_event[j-1];
      int val1 = events[j-1][2] + dp[i-1][pos]; // attend event-i
      int val2 = dp[i][j-1]; // not attend
      dp[i][j] = std::max(val1, val2);
    }
  }
  return dp[k][num_of_events];
}
