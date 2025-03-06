#pragma once

#include <containers/linked_list/linked_list.h>

inline ListNode *removeDuplicates(ListNode *head) {
    if (!head) return head;

    ListNode *lastNode = head;
    int value_seen = lastNode->val;

    ListNode *curr = lastNode->next;
    while(curr != nullptr) {
        if (curr->val != value_seen) {
            if (lastNode->next != curr) {
                lastNode->next = curr;
            }
            value_seen = curr->val;
            lastNode = curr;
        }
        curr = curr->next;
    }

    lastNode->next = nullptr;
    return head;
}