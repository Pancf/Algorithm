//
//  Solution1563.hpp
//  Algorithm
//
//  Created by focus on 10/3/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1563_hpp
#define Solution1563_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

class Solution1563 {
public:
  int DP(vector<vector<int>>& dp, vector<int>& prefixSum, int l, int r);
  int stoneGameV(vector<int>& stoneValue);
  
  static void test()
  {
    /**
       [6 2 3 4 5 5] -> [6 2 3] -> [2 3] -> [2] -> []
       [6 8 11 15 20 25]
     min(sum[0, i], sum(i, length - 1])
     find a pivot, making abs(sum[0, pos] - sum[pos + 1, n - 1]) minimum
     */
    vector<int> stones1{2,1,1};
    vector<int> stones2{7,7,7,7,7,7,7};
    vector<int> stones3{4};
    Solution1563 s;
    assert(s.stoneGameV(stones1) == 3);
    assert(s.stoneGameV(stones2) == 28);
    assert(s.stoneGameV(stones3) == 0);
  }
};

#endif /* Solution1563_hpp */
