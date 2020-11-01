//
//  Solution44.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution44_hpp
#define Solution44_hpp

#include <stdio.h>
#include <string>

class Solution44 {
public:
    bool isMatch(std::string s, std::string p);
    static void test()
    {
        Solution44 s = Solution44();
        printf("%s\n", s.isMatch("aa", "a") ? "true" : "false");
        printf("%s\n", s.isMatch("aa", "*") ? "true" : "false");
        printf("%s\n", s.isMatch("cb", "?a") ? "true" : "false");
        printf("%s\n", s.isMatch("adceb", "*a*b") ? "true" : "false");
        printf("%s\n", s.isMatch("acdcb", "a*c?b") ? "true" : "false");
    }
};

#endif /* Solution44_hpp */
