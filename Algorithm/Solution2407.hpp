//
//  Solution2407.hpp
//  Algorithm
//
//  Created by focus on 9/24/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution2407_hpp
#define Solution2407_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

using std::vector;

class Solution2407 {
public:
  int lengthOfLIS(vector<int>& nums, int k);
  static void test()
  {
    Solution2407 s;
    vector<int> nums1{4,2,1,4,3,4,5,8,15};
    vector<int> nums2{7,4,5,1,8,12,4,7};
    vector<int> nums3{1,5};
    assert(s.lengthOfLIS(nums1, 3) == 5);
    assert(s.lengthOfLIS(nums2, 5) == 4);
    assert(s.lengthOfLIS(nums3, 1) == 1);
  }
};

#endif /* Solution2407_hpp */
