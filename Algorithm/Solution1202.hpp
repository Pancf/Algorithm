//
//  Solution1202.hpp
//  Algorithm
//
//  Created by Pancf on 2020/8/4.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution1202_hpp
#define Solution1202_hpp

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution1202
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs);
    static void test()
    {
        string param = "zdcyxbwa";
        vector<vector<int>> pairs{{0,3},{4,6},{3,4},{1,7},{2,5},{5,7}};
        string ret = Solution1202().smallestStringWithSwaps(param, pairs);
        printf("%s\n", ret.c_str());
    }
};

#endif /* Solution1202_hpp */
