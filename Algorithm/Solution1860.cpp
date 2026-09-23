//
//  Solution1860.cpp
//  Algorithm
//
//  Created by focus on 9/23/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution1860.hpp"

vector<int> Solution1860::memLeak(int memory1, int memory2)
{
  if (memory1 == 0 && memory2 == 0) return {0, 0, 0};
  int second = 1;
  while ((memory1 - second) >= 0 || (memory2 - second) >= 0) {
    if (memory1 >= memory2) {
      memory1 -= second;
    } else {
      memory2 -= second;
    }
    second++;
  }
  return {second, memory1, memory2};
}
