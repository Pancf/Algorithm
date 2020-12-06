//
//  Solution104.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution104.hpp"
#include <algorithm>

int Solution104::maxDepth(TreeNode *root)
{
    if (!root) return 0;
    int leftDepth = 0, rightDepth = 0;
    if (!root->left && !root->right) return 1;
    if (root->left) leftDepth = maxDepth(root->left) + 1;
    if (root->right) rightDepth = maxDepth(root->right) + 1;
    return std::max(leftDepth, rightDepth);
}
