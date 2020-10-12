//
//  Solution23.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/12.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution23_hpp
#define Solution23_hpp

#include <stdio.h>
#include <vector>

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

class Solution23 {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
    static void test()
    {
        ListNode node3{5};
        ListNode node2{4, &node3};
        ListNode node1{1, &node2};
        ListNode node6{4};
        ListNode node5{3, &node6};
        ListNode node4{1, &node5};
        ListNode node8{6};
        ListNode node7{2, &node8};
        Solution23 s;
        std::vector<ListNode *> lists{&node1, &node4, &node7};
        auto res = s.mergeKLists(lists);
    }
};

#endif /* Solution23_hpp */
