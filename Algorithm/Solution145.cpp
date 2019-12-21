//
//  Solution145.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution145.hpp"
#include <stack>

using std::stack;

vector<int> Solution145::postorderTraversal(TreeNode *root) {
    vector<int> rv;
    if (!root) {
        return rv;
    }
    auto cur = root;
    // last用来记录上次访问过出栈的结点
    TreeNode *last = nullptr;
    stack<TreeNode *> st;
    while (cur || !st.empty()) {
        if (cur) {
            // 访问左子树
            st.push(cur);
            cur = cur->left;
        } else {
            auto top = st.top();
            if (!top->right || last == top->right) {
                // 只有栈顶结点右子树为空或者右子树已经被访问过时，才保存栈顶节点的值，然后出栈，
                // 代表以该结点为根节点的左右子树都已经被访问过
                rv.push_back(top->val);
                last = top;
                st.pop();
            } else {
                // 右子树不为空且未被访问时
                cur = top->right;
            }
        }
    }
    return rv;
}
