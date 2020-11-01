//
//  Solution42.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution42_hpp
#define Solution42_hpp

#include <stdio.h>
#include <vector>

class Solution42 {
public:
    int trap(std::vector<int>& height);
    static void test()
    {
        Solution42 s = Solution42();
        std::vector<int> case1{0,1,0,2,1,0,1,3,2,1,2,1};
        std::vector<int> case2{4,2,0,3,2,5};
        printf("%d\n", s.trap(case1));
        printf("%d\n", s.trap(case2));
    }
};

#endif /* Solution42_hpp */
