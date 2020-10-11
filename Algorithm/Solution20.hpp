//
//  Solution20.hpp
//  Algorithm
//
//  Created by Pancf on 2020/8/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution20_hpp
#define Solution20_hpp

#include <stdio.h>
#include <string>

using std::string;

class Solution20
{
public:
    bool isValid(string s);
    static void test()
    {
        string s = "]";
        bool valid = Solution20().isValid(s);
        printf("%s\n", valid ? "valid" : "invalid");
    }
};

#endif /* Solution20_hpp */
