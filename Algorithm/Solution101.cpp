//
//  Solution101.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/29.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution101.hpp"

bool is_same(Solution101::TreeNode *left, Solution101::TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if (left && right && left->val == right->val) {
        return is_same(left->left, right->right) && is_same(left->right, right->left);
    }
    return false;
}

bool Solution101::isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return is_same(root->left, root->right);
}
