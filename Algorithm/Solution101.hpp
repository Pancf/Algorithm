//
//  Solution101.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/29.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution101_hpp
#define Solution101_hpp

#include <stdio.h>

class Solution101 {
/**
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
    / \
   2   2
   / \ / \
  3  4 4  3

 But the following [1,2,2,null,3,null,3] is not:

    1
    / \
   2   2
    \   \
    3    3
  
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 ================================================================================================
 Accept details:
 Runtime: 4 ms, faster than 84.36% of C++ online submissions for Symmetric Tree.
 Memory Usage: 14.7 MB, less than 84.75% of C++ online submissions for Symmetric Tree.
 思路：这题用递归比迭代简单多了
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    bool isSymmetric(TreeNode* root);
    static void test() {
        TreeNode root{1};
        TreeNode node1{2};
        TreeNode node2{2};
        TreeNode node3{3};
        TreeNode node4{4};
        TreeNode node5{4};
        TreeNode node6{3};
        root.left = &node1;
        root.right = &node2;
        node1.left = &node3;
        node1.right = &node4;
        node2.left = &node5;
        node2.right = &node6;
        Solution101 s = Solution101();
        printf("%d\n", s.isSymmetric(&root));
    }
};
#endif /* Solution101_hpp */
