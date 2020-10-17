//
//  Solution34.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution34_hpp
#define Solution34_hpp

#include <stdio.h>
#include <vector>

class Solution34 {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target);
    static void test()
    {
        std::vector<int> v{1,2,3,3,3,3,4,5,9};
        Solution34 s = Solution34();
        auto res = s.searchRange(v, 3);
        printf("%d\t%d\n", res.front(), res.back());
    }
};

#endif /* Solution34_hpp */
