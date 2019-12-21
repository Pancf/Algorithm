//
//  Solution142.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution142_hpp
#define Solution142_hpp

#include <stdio.h>

class Solution142 {
/**
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

 To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 Note: Do not modify the linked list.
 
 Example 1:
 Input: head = [3,2,0,-4], pos = 1
 Output: tail connects to node index 1
 Explanation: There is a cycle in the linked list, where tail connects to the second node.


 Example 2:
 Input: head = [1,2], pos = 0
 Output: tail connects to node index 0
 Explanation: There is a cycle in the linked list, where tail connects to the first node.


 Example 3:
 Input: head = [1], pos = -1
 Output: no cycle
 Explanation: There is no cycle in the linked list.

 Follow-up:
 Can you solve it without using extra space?
 ================================================================================================
 Accept details:
 Runtime: 12 ms, faster than 76.79% of C++ online submissions for Linked List Cycle II.
 Memory Usage: 9.7 MB, less than 88.10% of C++ online submissions for Linked List Cycle II.
 思路：此题是141题的扩展，不仅仅是需要判断是否有环，还需要找到环的入口（即第一个进入环的链表结点）。使用141中快慢指针的做法，
 快、慢指针相遇时，相遇点在环内某个结点，快指针走的步数刚好是慢指针的两倍
 start----cycle entry------------meeting-----------end
 由此可得 length(start, meeting) = length(meeting, end) + length(cycle entry, meeting) => length(start, cycle entry) = length(meeting, end)
 因此在快慢指针相遇时另增一个新指针从start开始，和慢指针一样每次loop向前走一步，两者相遇点必然在cycle entry
 */
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *detectCycle(ListNode *head);
    static void test() {
        ListNode node1{1};
        ListNode node2{2};
        ListNode node3{3};
        ListNode node4{4};
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node2;
        Solution142 s = Solution142();
        printf("%d", s.detectCycle(&node1)->val);
    }
};
#endif /* Solution142_hpp */
