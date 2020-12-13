//
//  Solution124.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/13.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution124_hpp
#define Solution124_hpp

#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution124 {
public:
    int maxPathSum(TreeNode* root);
    static void test()
    {
        Solution124 s;
        TreeNode root{-10};
        TreeNode node1{9};
        TreeNode node2{20};
        TreeNode node3{15};
        TreeNode node4{7};
        root.left = &node1;
        root.right = &node2;
        node2.left = &node3;
        node2.right = &node4;
        auto res = s.maxPathSum(&root);
        printf("%d\n", res);
    }
};

#endif /* Solution124_hpp */
