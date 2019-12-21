//
//  Solution94.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution94.hpp"
#include <stack>

using std::stack;

vector<int> Solution94::inorderTraversal(TreeNode *root) {
    vector<int> rv;
    if (!root) {
        return rv;
    }
    auto cur = root;
    stack<TreeNode *> st;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            rv.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
    }
    return rv;
}
