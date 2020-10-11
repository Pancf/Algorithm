//
//  Solution21.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution21.hpp"

// double pointer太美妙了
ListNode* Solution21::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *head = nullptr;
    if (!l1) return l2;
    if (!l2) return l1;
    // 必须要将l1或l2向后走一格，否则后续(*pp)->next = l(1/2)会导致链表循环
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    // head指向新链表的头节点，pp保存head指针的地址，(*pp)指向新链表的当前节点
    ListNode** pp = &head;
    while (l1 && l2) {
        // update新链表当前节点的next
        if (l1->val < l2->val) {
            (*pp)->next = l1;
            l1 = l1->next;
        } else {
            (*pp)->next = l2;
            l2 = l2->next;
        }
        // 更新pp，(*pp)总是指向新链表的末尾节点
        pp = &((*pp)->next);
    }
    (*pp)->next = l1 ? l1 : l2;
    return head;
}
