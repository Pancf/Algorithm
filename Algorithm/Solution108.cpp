//
//  Solution108.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution108.hpp"

TreeNode* build(std::vector<int> &nums, int left, int right)
{
    if (left > right) return nullptr;
    // avoid int overflow
    int midIdx = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[midIdx]);
    root->left = build(nums, left, midIdx - 1);
    root->right = build(nums, midIdx + 1, right);
    return root;
}

TreeNode* Solution108::sortedArrayToBST(std::vector<int> &nums)
{
    if (nums.empty()) return nullptr;
    auto root = build(nums, 0, nums.size() - 1);
    return root;
}
