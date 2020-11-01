//
//  Solution54.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution54_hpp
#define Solution54_hpp

#include <stdio.h>
#include <vector>

class Solution54 {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
    static void test()
    {
        std::vector<std::vector<int>> input{
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
        };
        Solution54 s = Solution54();
        auto res = s.spiralOrder(input);
        for (int i = 0; i < res.size(); ++i) {
            printf("%d ", res[i]);
        }
    }
};

#endif /* Solution54_hpp */
