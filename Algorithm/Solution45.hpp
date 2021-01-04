//
//  Solution45.hpp
//  Algorithm
//
//  Created by Pancf on 2021/1/3.
//  

#ifndef Solution45_hpp
#define Solution45_hpp

#include <stdio.h>
#include <vector>

class Solution45 {
public:
    int jump(std::vector<int>& nums);
    static void test()
    {
        std::vector<int> nums1{5,9,3,2,1,0,2,3,3,1,0,0};
        std::vector<int> nums2{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
        Solution45 s;
        printf("%d\t%d\n", s.jump(nums1), s.jump(nums2));
    }
};

#endif /* Solution45_hpp */
