//
//  Solution563.hpp
//  Algorithm
//
//  Created by focus on 10/2/26.
//  Copyright © 2026 Pancf. All rights reserved.
//

#ifndef Solution563_hpp
#define Solution563_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

class Solution563 {
  
public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  std::pair<int, int> dfs(TreeNode* node);
  int findTilt(TreeNode* root);
  
  static TreeNode* buildTree(std::vector<int>& nodes, int pos)
  {
    if (pos >= nodes.size()) return nullptr;
    TreeNode* left = buildTree(nodes, pos * 2 + 1);
    TreeNode* right = buildTree(nodes, pos * 2 + 2);
    TreeNode* cur = new TreeNode(nodes[pos], left, right);
    return cur;
  }
  
  static void test()
  {
    std::vector<int> nodes1{1, 2, 3};
    std::vector<int> nodes2{4, 2, 9, 3, 5, 0, 7};
    std::vector<int> nodes3{21, 7, 14, 1, 1, 2, 2, 3, 3};
    Solution563 s;
    assert(s.findTilt(buildTree(nodes1, 0)) == 1);
    assert(s.findTilt(buildTree(nodes2, 0)) == 15);
    assert(s.findTilt(buildTree(nodes3, 0)) == 9);
  }
};
#endif /* Solution563_hpp */
