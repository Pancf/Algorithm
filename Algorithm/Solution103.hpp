//
//  Solution103.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution103_hpp
#define Solution103_hpp

#include <stdio.h>
#include <vector>

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution103 {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
    static void test()
    {
        TreeNode n1{15};
        TreeNode n2{7};
        TreeNode n3{9};
        TreeNode n4{20, &n1, &n2};
        TreeNode n5{3, &n3, &n4};
        Solution103 s;
        auto res = s.zigzagLevelOrder(&n5);
    }
};
#endif /* Solution103_hpp */
