//
//  Solution94.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution94_hpp
#define Solution94_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution94 {
/**
 Given a binary tree, return the inorder traversal of its nodes' values.

 Example:

 Input: [1,null,2,3]
    1
     \
      2
     /
    3

 Output: [1,3,2]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 ================================================================================================
 Accept details:
 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
 Memory Usage: 9.1 MB, less than 97.00% of C++ online submissions for Binary Tree Inorder Traversal.
 思路：和144题前序遍历类似，只不过前序遍历是栈顶左结点不为空时就保存结果（优先访问根节点），而中序遍历是栈顶左结点为空时保存结果
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<int> inorderTraversal(TreeNode* root);
    static void test() {
        TreeNode root{1};
        TreeNode node1{2};
        TreeNode node2{3};
        root.right = &node1;
        node1.left = &node2;
        Solution94 s = Solution94();
        auto rv = s.inorderTraversal(&root);
        for (auto ele : rv) {
            printf("%d ", ele);
        }
    }
};

#endif /* Solution94_hpp */
