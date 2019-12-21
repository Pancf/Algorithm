//
//  Solution141.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution141_hpp
#define Solution141_hpp

#include <stdio.h>

class Solution141 {
/**
 Given a linked list, determine if it has a cycle in it.

 To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 Example 1:
 Input: head = [3,2,0,-4], pos = 1
 Output: true
 Explanation: There is a cycle in the linked list, where tail connects to the second node.


 Example 2:
 Input: head = [1,2], pos = 0
 Output: true
 Explanation: There is a cycle in the linked list, where tail connects to the first node.


 Example 3:
 Input: head = [1], pos = -1
 Output: false
 Explanation: There is no cycle in the linked list.

 Follow up:

 Can you solve it using O(1) (i.e. constant) memory?
 ================================================================================================
 Accept details:
 Runtime: 8 ms, faster than 97.17% of C++ online submissions for Linked List Cycle.
 Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Linked List Cycle.
 思路：用快慢指针即可，慢指针每个loop向前走一步，快指针向前走两步，若有环则快指针一定会追上慢指针，若无环则快指针一定先到达链表尾部
 */
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    bool hasCycle(ListNode *head);
    static void test() {
        ListNode node1{1};
        ListNode node2{2};
        ListNode node3{3};
        ListNode node4{4};
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node2;
        Solution141 s = Solution141();
        printf("%d", s.hasCycle(&node1));
    }
};

#endif /* Solution141_hpp */
