//
//  Solution102.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/23.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution102_hpp
#define Solution102_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution102 {
/**
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 return its level order traversal as:

 [
   [3],
   [9,20],
   [15,7]
 ]
 ================================================================================================
 Accept details:
 Runtime: 8 ms, faster than 58.20% of C++ online submissions for Binary Tree Level Order Traversal.
 Memory Usage: 13.9 MB, less than 77.46% of C++ online submissions for Binary Tree Level Order Traversal.
 思路：二叉树的按层遍历，借用一个队列就完事了
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<vector<int>> levelOrder(TreeNode* root);
    static void test() {
        TreeNode root{3};
        TreeNode node1{9};
        TreeNode node2{20};
        TreeNode node3{15};
        TreeNode node4{7};
        root.left = &node1;
        root.right = &node2;
        node2.left = &node3;
        node2.right = &node4;
        Solution102 s = Solution102();
        auto rv = s.levelOrder(&root);
        for (auto level_vec : rv) {
            for (auto i : level_vec) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
};

#endif /* Solution102_hpp */
