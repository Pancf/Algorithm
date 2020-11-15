//
//  Solution103.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution103.hpp"
#include <queue>

std::vector<std::vector<int>> Solution103::zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if (!root) return res;
    std::queue<TreeNode *> q;
    TreeNode *sentinel = (TreeNode *)0;
    q.push(root);
    q.push(sentinel);
    int layer = 0;
    std::vector<int> values;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node == sentinel) {
            if (!q.empty()) q.push(sentinel);
            if (layer & 1) std::reverse(values.begin(), values.end());
            res.push_back(values);
            values.clear();
            layer++;
        } else {
            values.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}
