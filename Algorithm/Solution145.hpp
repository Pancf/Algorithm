//
//  Solution145.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution145_hpp
#define Solution145_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Solution145 {
/**
 Given a binary tree, return the postorder traversal of its nodes' values.

 Example:

 Input: [1,null,2,3]
    1
     \
      2
     /
    3

 Output: [3,2,1]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 ================================================================================================
 Accept details:
 Runtime: 4 ms, faster than 59.15% of C++ online submissions for Binary Tree Postorder Traversal.
 Memory Usage: 9.1 MB, less than 93.55% of C++ online submissions for Binary Tree Postorder Traversal.
 思路：迭代法的后续遍历要比前序、中序稍难一点，具体思路见实现文件的注释
 */
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<int> postorderTraversal(TreeNode* root);
    static void test() {
        TreeNode root{1};
        TreeNode node1{2};
        TreeNode node2{3};
        root.right = &node1;
        node1.left = &node2;
        Solution145 s = Solution145();
        auto rv = s.postorderTraversal(&root);
        for (auto ele : rv) {
            printf("%d ", ele);
        }
    }
};

#endif /* Solution145_hpp */
