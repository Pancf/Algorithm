//
//  Solution1636.hpp
//  Algorithm
//
//  Created by focus on 10/9/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1636_hpp
#define Solution1636_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

class Solution1636 {
public:
  std::vector<int> frequencySort(std::vector<int>& nums);
  static void test()
  {
    std::vector<int> nums1{1,1,2,2,2,3};
    std::vector<int> n1{3,1,1,2,2,2};
    std::vector<int> nums2{2,3,1,3,2};
    std::vector<int> n2{1,3,3,2,2};
    std::vector<int> nums3{-1,1,-6,4,5,-6,1,4,1};
    std::vector<int> n3{5,-1,4,4,-6,-6,1,1,1};
    Solution1636 s;
    assert(s.frequencySort(nums1) == n1);
    assert(s.frequencySort(nums2) == n2);
    assert(s.frequencySort(nums3) == n3);
  }
};

#endif /* Solution1636_hpp */
