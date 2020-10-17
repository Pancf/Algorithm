//
//  Solution33.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/14.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution33_hpp
#define Solution33_hpp

#include <stdio.h>
#include <vector>

class Solution33 {
public:
    int search(std::vector<int>& nums, int target);
    static void test()
    {
        std::vector<int> v{4,5,6,7,0,1,2};
        Solution33 s = Solution33();
        printf("%d\n", s.search(v, 0));
    }
};

#endif /* Solution33_hpp */
