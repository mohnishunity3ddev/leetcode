#pragma once

#include <containers/linked_list/linked_list.h>

ListNode *
reverseBetween(ListNode *head, int left, int right)
{
    if (left == right || head->next == nullptr) return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    int count = 1;
    while (curr != nullptr && count++ < left) {
        prev = curr;
        curr = curr->next;
    }
    ListNode *left_node = curr, *left_prev = prev;
    while (curr != nullptr && count++ <= right) {
        curr = curr->next;
    }
    ListNode *right_node = curr, *right_next = curr->next;

    curr = left_node->next;
    prev = left_node;
    while (curr != right_next) {
        ListNode *curr_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr_next;
    }

    if (left_prev) {
        left_prev->next = right_node;
    } else {
        head = right_node;
    }

    left_node->next = curr;
    return head;
}