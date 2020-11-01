//
//  Solution75.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution75_hpp
#define Solution75_hpp

#include <stdio.h>
#include <vector>

class Solution75 {
public:
    void sortColors(std::vector<int>& nums);
    static void test()
    {
        Solution75 s;
        std::vector<int> case1{2,0,2,1,1,0};
        s.sortColors(case1);
    }
};

#endif /* Solution75_hpp */
