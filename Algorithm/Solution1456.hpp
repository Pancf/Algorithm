//
//  Solution1456.hpp
//  Algorithm
//
//  Created by focus on 10/16/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1456_hpp
#define Solution1456_hpp

#include <stdio.h>
#include <assert.h>
#include <string>

class Solution1456 {
public:
  int maxVowels(std::string s, int k);
  static void test()
  {
    Solution1456 s;
    assert(s.maxVowels("abciiidef", 3) == 3);
    assert(s.maxVowels("aeiou", 2) == 2);
    assert(s.maxVowels("leetcode", 3) == 2);
  }
};

#endif /* Solution1456_hpp */
