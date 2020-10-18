//
//  Solution38.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution38_hpp
#define Solution38_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Solution38 {
public:
    std::string countAndSay(int n);
    static void test()
    {
        Solution38 s = Solution38();
        std::cout<<s.countAndSay(4)<<std::endl;
    }
};

#endif /* Solution38_hpp */
