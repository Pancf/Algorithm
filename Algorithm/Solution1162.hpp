//
//  Solution1162.hpp
//  Algorithm
//
//  Created by focus on 10/6/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1162_hpp
#define Solution1162_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

class Solution1162 {
public:
  int maxDistance(vector<vector<int>>& grid);
  static void test()
  {
    /**
     1 0 1    0 1 0
     0 0 0 -> 1 2 1
     1 0 1    0 1 0
     
     if grid[i][j] == 1 return 0
     if dp[i][j] > 0 return dp[i][j]
     dp[i][j] = min(dp[i-1][j], dp[i][j+1], dp[i+1][j], dp[i][j-1]) + 1
     */
    vector<vector<int>> grid1{{1,0,1},{0,0,0},{1,0,1}};
    vector<vector<int>> grid2{{1,0,0},{0,0,0},{0,0,0}};
    Solution1162 s;
    assert(s.maxDistance(grid1) == 2);
    assert(s.maxDistance(grid2) == 4);
  }
};
#endif /* Solution1162_hpp */
