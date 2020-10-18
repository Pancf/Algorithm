//
//  Solution41.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/18.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution41_hpp
#define Solution41_hpp

#include <stdio.h>
#include <vector>

class Solution41 {
public:
    int firstMissingPositive(std::vector<int>& nums);
    static void test()
    {
        Solution41 s = Solution41();
        std::vector<int> nums{7,8,9,11,12};
        printf("%d\n", s.firstMissingPositive(nums));
    }
};

#endif /* Solution41_hpp */
