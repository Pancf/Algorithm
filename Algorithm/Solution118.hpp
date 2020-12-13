//
//  Solution118.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution118_hpp
#define Solution118_hpp

#include <stdio.h>
#include <vector>

class Solution118 {
public:
    std::vector<std::vector<int>> generate(int numRows);
    static void test()
    {
        int row = 5;
        Solution118 s;
        auto res = s.generate(row);
    }
};

#endif /* Solution118_hpp */
