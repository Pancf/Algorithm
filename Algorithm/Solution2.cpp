//
//  Solution2.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/29.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution2.hpp"

Solution2::ListNode * Solution2::addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto l1_cur = l1;
    auto l2_cur = l2;
    ListNode *rv = new ListNode{-1};
    ListNode *prev = rv;
    int carry = 0;
    while (l1_cur || l2_cur || carry) {
        auto val = (l1_cur ? l1_cur->val : 0) + (l2_cur ? l2_cur->val : 0) + carry;
        carry = val / 10;
        val = val % 10;
        ListNode *node = new ListNode{val};
        prev->next = node;
        prev = prev->next;
        l1_cur = l1_cur ? l1_cur->next : l1_cur;
        l2_cur = l2_cur ? l2_cur->next : l2_cur;
    }
    return rv->next;
}
