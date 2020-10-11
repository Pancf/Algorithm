//
//  Solution21.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution21_hpp
#define Solution21_hpp

#include <stdio.h>

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    static void test()
    {
        ListNode node3{4};
        ListNode node2{2, &node3};
        ListNode node1{1, &node2};
        ListNode node6{4};
        ListNode node5{3, &node6};
        ListNode node4{1, &node5};
        Solution21 s;
        auto res = s.mergeTwoLists(&node1, &node4);
        while (res) {
            printf("%d\n", res->val);
            res = res->next;
        }
    }
};
#endif /* Solution21_hpp */
