//
//  Solution144.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution144.hpp"
#include <stack>

using std::stack;

vector<int> Solution144::preorderTraversal(TreeNode *root) {
    vector<int> rv;
    if (!root) {
        return rv;
    }
    auto cur = root;
    stack<TreeNode *> st;
    while (cur || !st.empty()) {
        if (cur) {
            //前序遍历则要保存当前结点的值，然后将结点压栈，向左走一步
            rv.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        } else {
            //栈顶结点的左子树为空时，出栈，然后访问出栈结点的右子树
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
    return rv;
}
