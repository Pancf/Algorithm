//
//  Solution1563.cpp
//  Algorithm
//
//  Created by focus on 10/3/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1563.hpp"

int Solution1563::DP(vector<vector<int>> &dp, vector<int>& prefixSum, int l, int r)
{
  if (l >= r) return 0;
  
  if (dp[l][r] != -1) return dp[l][r];
  
  int res = 0;
  for (int i = l; i < r; ++i) {
    int leftSum = prefixSum[i + 1] - prefixSum[l];
    int rightSum = prefixSum[r + 1] - prefixSum[i + 1];
    
    if (leftSum < rightSum) {
      res = std::max(res, leftSum + DP(dp, prefixSum, l, i));
    } else if (leftSum > rightSum) {
      res = std::max(res, rightSum + DP(dp, prefixSum, i + 1, r));
    } else {
      res = std::max({res,
        leftSum + DP(dp, prefixSum, l, i),
        rightSum + DP(dp, prefixSum, i + 1, r)});
    }
    
    if (2 * std::min(leftSum, rightSum) <= res) break;
  }
  dp[l][r] = res;
  return res;
}

int Solution1563::stoneGameV(vector<int>& stoneValue)
{
  int length = static_cast<int>(stoneValue.size());
  
  if (length == 1) return 0;
  
  vector<vector<int>> dp(length, vector<int>(length, -1));
  vector<int> prefixSum(length + 1, 0);
  
  for (int i = 0; i < length; ++i) {
    prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
  }
  
  return DP(dp, prefixSum, 0, length - 1);
}
