//
//  Solution98.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/26.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution98.hpp"
#include <vector>
#include <stack>

using std::stack;
using std::vector;

bool Solution98::isValidBST(TreeNode *root) {
    if (!root) {
        return true;
    }
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;
    auto cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            auto top = st.top();
            if (prev && prev->val >= top->val) {
                return false;
            } else {
                prev = top;
            }
            st.pop();
            cur = prev->right;
        }
    }
    return true;
}
//bool traversal(Solution98::TreeNode *p, vector<int> &v) {
//    if (!p) {
//        return true;
//    }
//    bool left_valid = traversal(p->left, v);
//    if (!left_valid) {
//        return false;
//    }
//    if (!v.empty() && p->val <= v.back()) {
//        return false;
//    } else {
//        v.push_back(p->val);
//    }
//    bool right_valid = traversal(p->right, v);
//    if (!right_valid) {
//        return false;
//    }
//    return true;
//}
//
//bool Solution98::isValidBST(TreeNode *root) {
//    if (!root) {
//        return true;
//    }
//    vector<int> vt;
//    return traversal(root, vt);
//}
