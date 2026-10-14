//
//  Solution1838.hpp
//  Algorithm
//
//  Created by focus on 10/12/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1838_hpp
#define Solution1838_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

class Solution1838 {
public:
  int maxFrequency(std::vector<int>& nums, int k);
  static void test()
  {
    std::vector<int> nums1{1, 2, 4};
    std::vector<int> nums2{1, 4, 8, 13};
    std::vector<int> nums3{3, 9, 6};
    Solution1838 s;
    assert(s.maxFrequency(nums1, 5) == 3);
    assert(s.maxFrequency(nums2, 5) == 2);
    assert(s.maxFrequency(nums3, 2) == 1);
  }
};

#endif /* Solution1838_hpp */
