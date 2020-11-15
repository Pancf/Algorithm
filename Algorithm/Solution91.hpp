//
//  Solution91.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/9.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution91_hpp
#define Solution91_hpp

#include <stdio.h>
#include <string>

class Solution91 {
public:
    int numDecodings(std::string s);
    static void test()
    {
        Solution91 s;
        std::string s1{"12"};
        std::string s2{"226"};
        std::string s3{"0"};
        printf("%d\n", s.numDecodings(s1));
        printf("%d\n", s.numDecodings(s2));
        printf("%d\n", s.numDecodings(s3));
    }
};

#endif /* Solution91_hpp */
