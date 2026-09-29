//
//  Solution2385.cpp
//  Algorithm
//
//  Created by focus on 9/28/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution2385.hpp"
#include <queue>

/**
 traverse in post order
 @return first means whether find key node or not, second means depth
 */
std::pair<bool, int> Solution2385::dfs(TreeNode* node, int start)
{
  if (!node) return {false, 0};
  int depth = 0;
  
  auto left_res = dfs(node->left, start);
  auto right_res = dfs(node->right, start);
  
  if (node->val == start) {
    // for key node, calculate max distance from current to bottom
    max_distance_ = std::max(left_res.second, right_res.second);
    // reset depth info
    return {true, 0};
  }
  if (left_res.first || right_res.first) {
    // if find key node in subtree, sum depths as distance
    int distance = left_res.second + right_res.second + 1;
    max_distance_ = std::max(max_distance_, distance);
    return {true, (left_res.first ? left_res.second : right_res.second) + 1};
  } else {
    // not find key node in subtree
    depth = std::max(left_res.second, right_res.second) + 1;
  }
  
  return {false, depth};
}

int Solution2385::amountOfTime(TreeNode* root, int start)
{
  /**
   1
    \
     2
    / \
   3  *4*
  /
  5
   */
  dfs(root, start);
  return max_distance_;
}
