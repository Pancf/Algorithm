//
//  Solution160.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution160.hpp"

Solution160::ListNode * Solution160::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    auto ptr1 = headA;
    auto ptr2 = headB;
    while (ptr1 != ptr2) {
        ptr1 = ptr1 ? ptr1->next : headB;
        ptr2 = ptr2 ? ptr2->next : headA;
    }
    return ptr1;
}
