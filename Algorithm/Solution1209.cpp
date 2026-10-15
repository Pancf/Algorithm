//
//  Solution1209.cpp
//  Algorithm
//
//  Created by focus on 10/14/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1209.hpp"
#include <vector>

std::string Solution1209::removeDuplicates(std::string s, int k)
{
  std::vector<std::pair<char, int>> p;
  for (auto c : s) {
    if (!p.empty()) {
      auto [cur, freq] = p.back();
      if (cur == c) {
        if (freq + 1 == k) {
          p.pop_back();
        } else {
          p.back().second += 1;
        }
      } else {
        p.push_back({c, 1});
      }
    } else {
      p.push_back({c, 1});
    }
  }
  std::string res;
  for (auto [c, freq] : p) {
    res.append(freq, c);
  }
  return res;
}
