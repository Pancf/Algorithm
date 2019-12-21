//
//  Solution144.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution144_hpp
#define Solution144_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution144 {
/**
 Given a binary tree, return the preorder traversal of its nodes' values.

 Example:

 Input: [1,null,2,3]
    1
     \
      2
     /
    3

 Output: [1,2,3]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 ================================================================================================
 Accept details:
 Runtime: 8 ms, faster than 59.97% of C++ online submissions for Binary Tree Preorder Traversal.
 Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
 思路：递归解法借用了函数调用栈的特性，要使用迭代解法的话自己维护一个遍历栈即可。
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<int> preorderTraversal(TreeNode* root);
    static void test() {
        TreeNode root{1};
        TreeNode node1{2};
        TreeNode node2{3};
        root.right = &node1;
        node1.left = &node2;
        Solution144 s = Solution144();
        auto rv = s.preorderTraversal(&root);
        for (auto ele : rv) {
            printf("%d ", ele);
        }
    }
};

#endif /* Solution144_hpp */
