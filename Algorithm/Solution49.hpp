//
//  Solution49.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution49_hpp
#define Solution49_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Solution49 {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
    static void test()
    {
        Solution49 s = Solution49();
        std::vector<std::string> input{"eat","tea","tan","ate","nat","bat"};
        auto res = s.groupAnagrams(input);
    }
};

#endif /* Solution49_hpp */
