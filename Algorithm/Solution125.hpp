//
//  Solution125.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution125_hpp
#define Solution125_hpp

#include <stdio.h>
#include <string>

class Solution125 {
public:
    bool isPalindrome(std::string s);
    static void test()
    {
        std::string str1{"0P"};
        std::string str2{"race a car"};
        Solution125 s;
        printf("%d %d\n", s.isPalindrome(str1), s.isPalindrome(str2));
    }
};

#endif /* Solution125_hpp */
