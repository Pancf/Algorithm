//
//  Solution15.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution15_hpp
#define Solution15_hpp

#include <stdio.h>
#include <vector>

class Solution15 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    static void test()
    {
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        Solution15 s = Solution15();
        auto res = s.threeSum(nums);
    }
};

#endif /* Solution15_hpp */
