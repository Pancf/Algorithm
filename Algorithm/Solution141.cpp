//
//  Solution141.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution141.hpp"

bool Solution141::hasCycle(ListNode *head) {
    if (!head) {
        return false;
    }
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head->next;
    while (fast_ptr && fast_ptr->next) {
        if (slow_ptr == fast_ptr) {
            return true;
        }
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return false;
}
