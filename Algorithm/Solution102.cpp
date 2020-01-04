//
//  Solution102.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/23.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution102.hpp"
#include <queue>

using std::queue;

vector<vector<int>> Solution102::levelOrder(TreeNode *root) {
    vector<vector<int>> rv;
    if (!root) {
        return rv;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        size_t level_size = q.size();
        vector<int> level_node;
        for (size_t i = 0; i < level_size; ++i) {
            auto top = q.front();
            level_node.push_back(top->val);
            if (top->left) {
                q.push(top->left);
            }
            if (top->right) {
                q.push(top->right);
            }
            q.pop();
        }
        rv.push_back(level_node);
    }
    return rv;
}
