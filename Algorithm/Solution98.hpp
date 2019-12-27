//
//  Solution98.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/26.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution98_hpp
#define Solution98_hpp

#include <stdio.h>

class Solution98 {
/**
 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 ================================================================================================
 Accept details:
 Runtime: 16 ms, faster than 63.77% of C++ online submissions for Validate Binary Search Tree.
 Memory Usage: 21.7 MB, less than 5.21% of C++ online submissions for Validate Binary Search Tree.
 思路：如果是二叉搜索出，按中序遍历得到的结果应该是一个递增序列。使用一个vector<int>保存中序遍历的结果，插入之前判断
 当前遍历结点是否符合递增要求（只需要判断当前结点的值是否大于vector.back），满足要求则插入，不满足则early return false。
 迭代解法可以模仿94题，增加一个指针指向前一个pop掉的结点，往后每次pop前判断一下即将pop的结点是否大于前一个。
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    bool isValidBST(TreeNode* root);
    static void test() {
        TreeNode root{10};
        TreeNode node1{5};
        TreeNode node2{15};
        TreeNode node3{6};
        TreeNode node4{20};
        root.left = &node1;
        root.right = &node2;
        node2.left = &node3;
        node2.right = &node4;
        Solution98 s = Solution98();
        printf("%d\n", s.isValidBST(&root));
    }
};

#endif /* Solution98_hpp */
