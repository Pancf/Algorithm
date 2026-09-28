//
//  Solution1422.cpp
//  Algorithm
//
//  Created by focus on 9/28/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1422.hpp"
#include <vector>

int Solution1422::maxScore(string s)
{
  /**
   ORIGINAL SOLUTION
   int length = static_cast<int>(s.length());
   std::vector<int> sum0(length, 0), sum1(length, 0);
   int counter = 0;
   for (int i = 0; i < length - 1; ++i) {
     if (s[i] == '0') {
       counter++;
       sum0[i] = counter;
     }
   }
   counter = 0;
   for (int i = length - 1; i > 0; --i) {
     if (s[i] == '1') {
       counter++;
       sum1[i] = counter;
     }
   }
   int res = INT_MIN;
   for (int i = 0; i < length - 1; ++i) {
     res = std::max(res, sum0[i] + sum1[i + 1]);
   }
   return res;
  */
  // max(left_zero + right_one)
  // -> max(left_zero + (all_one - left_one))
  // -> max((left_zero - left_one) + all_one)
  // the art of math
  int cnt0 = 0, cnt1 = 0, res = INT_MIN;
  for (int i = 0; i < s.length(); ++i) {
    s[i] == '0' ? cnt0++ : cnt1++;
    if (i != s.length() - 1) res = std::max(res, cnt0 - cnt1);
  }
  return res + cnt1;
}
