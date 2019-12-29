//
//  Solution2.hpp
//  Algorithm
//
//  Created by Pancf on 2019/12/29.
//  Copyright © 2019 Pancf. All rights reserved.
//

#ifndef Solution2_hpp
#define Solution2_hpp

#include <stdio.h>

class Solution2 {
/**
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Example:

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 ================================================================================================
 Accept details:
 Runtime: 28 ms, faster than 32.25% of C++ online submissions for Add Two Numbers.
 Memory Usage: 10.3 MB, less than 87.43% of C++ online submissions for Add Two Numbers.
 */
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    static void test() {
        ListNode num1{2};
        ListNode num2{4};
        ListNode num3{3};
        num1.next = &num2;
        num2.next = &num3;
        ListNode num4{5};
        ListNode num5{6};
        ListNode num6{4};
        num4.next = &num5;
        num5.next = &num6;
        Solution2 s = Solution2();
        auto rv = s.addTwoNumbers(&num1, &num4);
        while (rv) {
            printf("%d", rv->val);
            rv = rv->next;
        }
        printf("\n");
    }
};

#endif /* Solution2_hpp */
