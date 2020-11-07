//
//  Solution76.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/7.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution76_hpp
#define Solution76_hpp

#include <stdio.h>
#include <string>

class Solution76 {
public:
    std::string minWindow(std::string s, std::string t);
    static void test()
    {
        std::string s = "ADOBECODEBANC";
        std::string t = "ABC";
        Solution76 solution;
        // expect out "BANC"
        printf("%s\n", solution.minWindow(s, t).c_str());
    }
};

#endif /* Solution76_hpp */
