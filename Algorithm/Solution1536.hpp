//
//  Solution1536.hpp
//  Algorithm
//
//  Created by focus on 9/30/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1536_hpp
#define Solution1536_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

class Solution1536 {
public:
  int minSwaps(vector<vector<int>>& grid);
  static void test()
  {
    vector<vector<int>> grid1{{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    vector<vector<int>> grid2{{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    vector<vector<int>> grid3{{1,0,0},{1,1,0},{1,1,1}};
    vector<vector<int>> grid4{{1,0,0,0,0,0},{0,1,0,1,0,0},{1,0,0,0,0,0},{1,1,1,0,0,0},{1,1,0,1,0,0},{1,0,0,0,0,0}};
    Solution1536 s;
    assert(s.minSwaps(grid1) == 3);
    assert(s.minSwaps(grid2) == -1);
    assert(s.minSwaps(grid3) == 0);
    assert(s.minSwaps(grid4) == 2);
  }
};

#endif /* Solution1536_hpp */
