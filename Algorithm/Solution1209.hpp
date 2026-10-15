//
//  Solution1209.hpp
//  Algorithm
//
//  Created by focus on 10/14/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1209_hpp
#define Solution1209_hpp

#include <stdio.h>
#include <assert.h>
#include <string>

class Solution1209 {
public:
  std::string removeDuplicates(std::string s, int k);
  static void test()
  {
    std::string s1 = "abcd";
    std::string s2 = "deeedbbcccbdaa";
    std::string s3 = "pbbcggttciiippooaais";
    Solution1209 s;
    assert(s.removeDuplicates(s1, 2) == "abcd");
    assert(s.removeDuplicates(s2, 3) == "aa");
    assert(s.removeDuplicates(s3, 2) == "ps");
  }
};

#endif /* Solution1209_hpp */
