//
//  Solution19.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution19.hpp"

// 一次遍历移除从链表末尾开始计数的第n个节点
ListNode* Solution19::removeNthFromEnd(ListNode* head, int n)
{
    // double pointer is awesome
    ListNode** slow = &head;
    ListNode* fast = head;
    while (n--) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = &((*slow)->next);
    }
    // entry is the node to be deleted
    ListNode* entry = *slow;
    *slow = entry->next;
    delete entry;
    return head;
}
