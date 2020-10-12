//
//  Solution23.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/12.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution23.hpp"

// 双链表合并的递归写法
ListNode* merge2Lists(ListNode* l1, ListNode* l2)
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    } else {
        l2->next = merge2Lists(l1, l2->next);
        return l2;
    }
}

// k = lists.size(), n = average list, 时间复杂度 = k/2 * 2n + k/4 * 4n + ... + 1 * kn = kn * logk
ListNode* Solution23::mergeKLists(std::vector<ListNode *> &lists)
{
    if (lists.size() == 0) return nullptr;
    size_t len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; ++i) {
            lists[i] = merge2Lists(lists[i], lists[len - i - 1]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}
