//
//  Solution1094.hpp
//  Algorithm
//
//  Created by focus on 10/8/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1094_hpp
#define Solution1094_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

class Solution1094 {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity);
  static void test()
  {
    vector<vector<int>> trips{{2,1,5},{3,3,7}};
    vector<vector<int>> trips1{{3,2,7},{3,7,9},{8,3,9}};
    Solution1094 s;
    assert(!s.carPooling(trips, 4));
    assert(s.carPooling(trips, 5));
    assert(s.carPooling(trips1, 11));
  }
};

#endif /* Solution1094_hpp */
