//
//  Solution563.cpp
//  Algorithm
//
//  Created by focus on 10/2/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#include "Solution563.hpp"

std::pair<int, int> Solution563::dfs(TreeNode *node)
{
  if (!node) return {0, 0};
  
  auto left_res = dfs(node->left);
  auto right_res = dfs(node->right);
  
  int left_sum = left_res.first;
  int left_tilt = left_res.second;
  int right_sum = right_res.first;
  int right_tilt = right_res.second;
  
  return {left_sum + right_sum + node->val, left_tilt + right_tilt + std::abs(left_sum - right_sum)};
}

int Solution563::findTilt(TreeNode *root)
{
  auto res = dfs(root);
  return res.second;
}
