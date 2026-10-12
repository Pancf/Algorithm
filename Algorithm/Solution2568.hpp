//
//  Solution2568.hpp
//  Algorithm
//
//  Created by focus on 10/10/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution2568_hpp
#define Solution2568_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

class Solution2568 {
public:
  int minImpossibleOR(std::vector<int>& nums);
  static void test()
  {
    std::vector<int> nums1{2, 1};
    std::vector<int> nums2{5, 3, 2};
    Solution2568 s;
    assert(s.minImpossibleOR(nums1) == 4);
    assert(s.minImpossibleOR(nums2) == 1);
  }
};

#endif /* Solution2568_hpp */
