//
//  Solution105.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution105.hpp"

static TreeNode* build(std::vector<int> &preorder, std::vector<int> &inorder, int leftIdx, int rightIdx, int rootIdxInPreorder)
{
    if (leftIdx == rightIdx) {
        // leaf node
        TreeNode *node = new TreeNode(inorder[leftIdx]);
        return node;
    }
    int rootIdx = leftIdx;
    for (int i = leftIdx; i <= rightIdx; ++i) {
        if (preorder[rootIdxInPreorder] == inorder[i]) {
            rootIdx = i;
            break;
        }
    }
    TreeNode *root = new TreeNode(inorder[rootIdx]);
    if (rootIdx > leftIdx) root->left = build(preorder, inorder, leftIdx, rootIdx - 1, rootIdxInPreorder + 1);
    if (rootIdx < rightIdx) root->right = build(preorder, inorder, rootIdx + 1, rightIdx, rootIdxInPreorder + rootIdx - leftIdx + 1);
    return root;
}

TreeNode* Solution105::buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty()) return nullptr;
    int size = (int)preorder.size();
    auto root = build(preorder, inorder, 0, size - 1, 0);
    return root;
}
