//
//  Solution2385.hpp
//  Algorithm
//
//  Created by focus on 9/28/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution2385_hpp
#define Solution2385_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

class Solution2385 {
  int max_distance_{0};
public:
  struct TreeNode {
    int val{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    TreeNode(int x): val(x) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
  };
  
  int amountOfTime(TreeNode* root, int start);
  [[maybe_unused]] std::pair<bool, int> dfs(TreeNode* node, int start);
  
  static TreeNode* buildTree(std::vector<int>& values, int pos)
  {
    if (pos >= values.size() || values[pos] == -1) return nullptr;
    TreeNode* node = new TreeNode(values[pos]);
    node->left = buildTree(values, pos * 2 + 1);
    node->right = buildTree(values, pos * 2 + 2);
    return node;
  }
  static void test()
  {
    std::vector<int> val1{1,5,3,-1,4,10,6,-1,-1,9,2};
    std::vector<int> val2{1};
    auto* root1 = buildTree(val1, 0);
    auto* root2 = buildTree(val2, 0);
    Solution2385 s;
    assert(s.amountOfTime(root1, 3) == 4);
    assert(s.amountOfTime(root2, 1) == 0);
  }
};

#endif /* Solution2385_hpp */
