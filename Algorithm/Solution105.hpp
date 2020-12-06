//
//  Solution105.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution105_hpp
#define Solution105_hpp

#include <stdio.h>
#include <vector>

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

class Solution105 {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    static void test()
    {
        std::vector<int> preorder{3,9,20,15,7};
        std::vector<int> inorder{9,3,15,20,7};
        Solution105 s;
        auto root = s.buildTree(preorder, inorder);
    }
};

#endif /* Solution105_hpp */
