//
//  Solution13.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution13_hpp
#define Solution13_hpp

#include <stdio.h>
#include <string>

class Solution13 {
public:
    int romanToInt(std::string s);
    static void test()
    {
        std::string s = "MCMXCIV";
        Solution13 solution = Solution13();
        printf("%d\n", solution.romanToInt(s));
    }
};

#endif /* Solution13_hpp */
