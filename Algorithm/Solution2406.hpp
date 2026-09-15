//
//  Solution2406.hpp
//  Algorithm
//
//  Created by focus on 9/15/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution2406_hpp
#define Solution2406_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution2406 {
public:
  int minGroups(vector<vector<int>>& intervals);
  static void test()
  {
    Solution2406 s;
    vector<vector<int>> intervals1{{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    assert(s.minGroups(intervals1) == 3);
    vector<vector<int>> intervals2{{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    assert(s.minGroups(intervals2) == 1);
  }
};

#endif /* Solution2406_hpp */
