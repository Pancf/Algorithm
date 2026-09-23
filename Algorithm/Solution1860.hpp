//
//  Solution1860.hpp
//  Algorithm
//
//  Created by focus on 9/23/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1860_hpp
#define Solution1860_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution1860 {
public:
  vector<int> memLeak(int memory1, int memory2);
  static void test()
  {
    Solution1860 s;
    assert((s.memLeak(2, 2) == vector<int>{3,1,0}));
    assert((s.memLeak(8, 11) == vector<int>{6,0,4}));
  }
};

#endif /* Solution1860_hpp */
