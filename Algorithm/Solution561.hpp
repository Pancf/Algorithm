//
//  Solution561.hpp
//  Algorithm
//
//  Created by focus on 9/11/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution561_hpp
#define Solution561_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution561 {
public:
  int arrayPairSum(vector<int>& nums);
  static void test()
  {
    vector<int> nums1{1, 4, 3, 2};
    vector<int> nums2{6, 2, 6, 5, 1, 2};
    Solution561 s;
    assert(s.arrayPairSum(nums1) == 4);
    assert(s.arrayPairSum(nums2) == 9);
  }
};

#endif /* Solution561_hpp */
