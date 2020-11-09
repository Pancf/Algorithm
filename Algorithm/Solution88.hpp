//
//  Solution88.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution88_hpp
#define Solution88_hpp

#include <stdio.h>
#include <vector>

class Solution88 {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    static void test()
    {
        Solution88 s;
        std::vector<int> nums1{1,2,3,0,0,0};
        std::vector<int> nums2{2,5,6};
        s.merge(nums1, 3, nums2, 3);
    }
};

#endif /* Solution88_hpp */
