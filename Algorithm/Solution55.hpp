//
//  Solution55.hpp
//  Algorithm
//
//  Created by Pancf on 2020/8/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution55_hpp
#define Solution55_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution55
{
public:
    bool canJump(vector<int>& nums);
    static void test()
    {
        vector<int> param{2, 3, 1, 1, 4};
        bool can = Solution55().canJump(param);
        printf("%s jump\n", can ? "can" : "can't");
    }
};

#endif /* Solution55_hpp */
