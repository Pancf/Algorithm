//
//  Solution108.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution108_hpp
#define Solution108_hpp

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

class Solution108 {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums);
    static void test()
    {
        std::vector<int> nums{-10,-3,0,5,9};
        Solution108 s;
        auto root = s.sortedArrayToBST(nums);
    }
};

#endif /* Solution108_hpp */
