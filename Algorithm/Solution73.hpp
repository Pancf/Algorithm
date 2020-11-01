//
//  Solution73.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution73_hpp
#define Solution73_hpp

#include <stdio.h>
#include <vector>

class Solution73 {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix);
    static void test()
    {
        Solution73 s;
        std::vector<std::vector<int>> case1{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        s.setZeroes(case1);
    }
};

#endif /* Solution73_hpp */
