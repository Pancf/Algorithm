//
//  Solution19.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/11.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution19_hpp
#define Solution19_hpp

#include <stdio.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    static void test()
    {
        ListNode node5{5, nullptr};
        ListNode node4{4, &node5};
        ListNode node3{3, &node4};
        ListNode node2{2, &node3};
        ListNode node1{1, &node2};
        Solution19 s;
        auto res = s.removeNthFromEnd(&node1, 2);
        while (res) {
            printf("%d\n", res->val);
            res = res->next;
        }
    }
};

#endif /* Solution19_hpp */
