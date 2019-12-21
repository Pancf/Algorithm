//
//  Solution142.cpp
//  Algorithm
//
//  Created by Pancf on 2019/12/21.
//  Copyright © 2019 Pancf. All rights reserved.
//

#include "Solution142.hpp"

Solution142::ListNode * Solution142::detectCycle(ListNode *head) {
    if (!head) {
        return nullptr;
    }
    auto slow_ptr = head;
    auto fast_ptr = head;
    while (fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (fast_ptr == slow_ptr) {
            auto ano_ptr = head;
            while (ano_ptr != slow_ptr) {
                ano_ptr = ano_ptr->next;
                slow_ptr = slow_ptr->next;
            }
            return ano_ptr;
        }
    }
    return nullptr;
}
