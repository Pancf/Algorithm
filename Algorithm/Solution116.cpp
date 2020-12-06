//
//  Solution116.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/6.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution116.hpp"
#include <queue>

Node* Solution116::connect(Node *root)
{
    if (!root) return nullptr;
    std::queue<Node *> q;
    Node *sentinel = nullptr;
    q.push(root);
    q.push(sentinel);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node != sentinel) {
            node->next = (q.front() == sentinel) ? nullptr : q.front();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (node == sentinel && !q.empty()) q.push(sentinel);
    }
    return root;
}
