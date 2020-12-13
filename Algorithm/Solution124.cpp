//
//  Solution124.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution124.hpp"
#include <limits.h>
#include <algorithm>

int _pathSum(TreeNode *node, int &maxVal)
{
    if (node == nullptr) return 0;
    // 左子树中包含node->left节点的路径最大值
    int maxOfLeft = std::max(_pathSum(node->left, maxVal), 0);
    // 右子树中包含node->right节点的路径最大值
    int maxOfRight = std::max(_pathSum(node->right, maxVal), 0);
    maxVal = std::max(maxVal, maxOfLeft + node->val + maxOfRight);
    // 以当前节点为根节点的路径最大值
    return std::max(maxOfLeft, maxOfRight) + node->val;
}

int Solution124::maxPathSum(TreeNode *root)
{
    int maxVal = INT_MIN;
    _pathSum(root, maxVal);
    return maxVal;
}
