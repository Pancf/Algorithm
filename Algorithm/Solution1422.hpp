//
//  Solution1422.hpp
//  Algorithm
//
//  Created by focus on 9/28/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution1422_hpp
#define Solution1422_hpp

#include <stdio.h>
#include <assert.h>
#include <string>

using std::string;

class Solution1422 {
public:
  int maxScore(string s);
  static void test()
  {
    Solution1422 s;
    string str1{"011101"};
    string str2{"00111"};
    string str3{"1111"};
    assert(s.maxScore(str1) == 5);
    assert(s.maxScore(str2) == 5);
    assert(s.maxScore(str3) == 3);
  }
};

#endif /* Solution1422_hpp */
