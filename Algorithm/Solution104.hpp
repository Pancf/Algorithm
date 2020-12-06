//
//  Solution104.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution104_hpp
#define Solution104_hpp

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

class Solution104 {
public:
    int maxDepth(TreeNode* root);
    static void test()
    {
        TreeNode root(3);
        TreeNode node1(9);
        TreeNode node2(20);
        TreeNode node3(15);
        TreeNode node4(7);
        root.left = &node1;
        root.right = &node2;
        node2.left = &node3;
        node2.right = &node4;
        Solution104 s;
        printf("%d\n", s.maxDepth(&root));
    }
};

#endif /* Solution104_hpp */
