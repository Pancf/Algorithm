//
//  Solution1751.hpp
//  Algorithm
//
//  Created by focus on 9/17/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1751_hpp
#define Solution1751_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution1751 {
public:
  int maxValue(vector<vector<int>>& events, int k);
  static void test()
  {
    vector<vector<int>> events1{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    vector<vector<int>> events2{{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    vector<vector<int>> events3{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    vector<vector<int>> events4{{19,42,7},{41,73,15},{52,73,84},{84,92,96},{6,64,50},{12,56,27},{22,74,44},{38,85,61}};
    Solution1751 s;
    assert(s.maxValue(events1, 2) == 7);
    assert(s.maxValue(events2, 2) == 10);
    assert(s.maxValue(events3, 3) == 9);
    assert(s.maxValue(events4, 5) == 187);
  }
};

#endif /* Solution1751_hpp */
