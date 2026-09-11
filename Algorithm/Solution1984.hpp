//
//  Solution1984.hpp
//  Algorithm
//
//  Created by focus on 9/10/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1984_hpp
#define Solution1984_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

class Solution1984 {
public:
  int minimumDifference(vector<int>& nums, int k);
  static void test()
  {
    vector<int> nums1{90};
    vector<int> nums2{9,4,1,7};
    Solution1984 s;
    assert(s.minimumDifference(nums1, 1) == 0);
    assert(s.minimumDifference(nums2, 2) == 2);
  }
};

#endif /* Solution1984_hpp */
