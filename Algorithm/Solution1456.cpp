//
//  Solution1456.cpp
//  Algorithm
//
//  Created by focus on 10/16/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1456.hpp"

static inline bool isVowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int Solution1456::maxVowels(std::string s, int k)
{
  // f(i, i+k)
  // f(i+1, i+k+1) -> f(i,i+k) - f(i) + f(i+k+1)
  // f(i+2, i+k+2) -> f(i+1, i+k+1) - f(i+1) + f(i+k+2)
  int windowNum = 0;
  for (int i = 0; i < k; ++i) {
    if (isVowel(s[i])) windowNum++;
  }
  int res = windowNum;
  for (int i = 1; i <= s.size() - k; ++i) {
    windowNum = windowNum - (isVowel(s[i - 1]) ? 1 : 0) + (isVowel(s[i + k - 1]) ? 1 : 0);
    res = std::max(res, windowNum);
  }
  return res;
}
