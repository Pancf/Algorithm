//
//  Solution66.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution66_hpp
#define Solution66_hpp

#include <stdio.h>
#include <vector>

class Solution66 {
public:
    std::vector<int> plusOne(std::vector<int>& digits);
    static void test()
    {
        Solution66 s = Solution66();
        std::vector<int> case1{4, 3, 2, 1};
        std::vector<int> case2{1, 9};
        std::vector<int> case3{9, 9};
        auto res1 = s.plusOne(case1);
        auto res2 = s.plusOne(case2);
        auto res3 = s.plusOne(case3);
        for (int i = 0; i < res1.size(); ++i) {
            printf("%d", res1[i]);
        }
        printf("\n");
        for (int i = 0; i < res2.size(); ++i) {
            printf("%d", res2[i]);
        }
        printf("\n");
        for (int i = 0; i < res3.size(); ++i) {
            printf("%d", res3[i]);
        }
        printf("\n");
    }
};

#endif /* Solution66_hpp */
