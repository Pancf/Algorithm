//
//  Solution160.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution160_hpp
#define Solution160_hpp

#include <stdio.h>

class Solution160 {
/**
 Write a program to find the node at which the intersection of two singly linked lists begins.

 For example, the following two linked lists:

 begin to intersect at node c1.
 
 Example 1:


 Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 Output: Reference of the node with value = 8
 Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
  

 Example 2:


 Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 Output: Reference of the node with value = 2
 Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
  

 Example 3:


 Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 Output: null
 Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
 Explanation: The two lists do not intersect, so return null.
  

 Notes:

 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 ================================================================================================
 Accept details:
 Runtime: 44 ms, faster than 95.64% of C++ online submissions for Intersection of Two Linked Lists.
 Memory Usage: 16.7 MB, less than 94.44% of C++ online submissions for Intersection of Two Linked Lists.
 思路：根据题意，如果这两条链表有交点，因为交点以后是共享的，即两条链表的长度之差就是交点前面的长度差值。所以l可以先获取各自的长度，然后让更长的那条链表
 先向前走长度之差，再同时向前走，若有结点则必然同时到达。若无交点则同时到达链表尾部。但这种做法需要两次O(n)的遍历。事实上我们也可不计算长度之差，让他们同时
 向前走，短链表先走到尾部，然后跳到长链表头，同理长链表走到尾部后跳到短链表，如果有交点也会在交点相遇。如果没有交点则同时走到尾部两者同时为空指针。
 自已经跳过一次链表。
 */
    
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    static void test() {
        ListNode node1{4};
        ListNode node2{1};
        ListNode node3{8};
        ListNode node4{4};
        ListNode node5{5};
        ListNode node6{5};
        ListNode node7{0};
        ListNode node8{1};
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node5;
        node6.next = &node7;
        node7.next = &node8;
        node8.next = &node3;
        Solution160 s = Solution160();
        printf("%d\n", s.getIntersectionNode(&node1, &node6)->val);
    }
};

#endif /* Solution160_hpp */
