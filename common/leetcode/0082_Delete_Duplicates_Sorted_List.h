#pragma once

#include <containers/linked_list/linked_list.h>

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;

    ListNode *pp = nullptr;
    ListNode *p = head;
    ListNode *c = head->next;
    while (c != nullptr) {
        if (c->val != p->val) {
            if (p->next != c) {
                if (pp)
                    pp->next = c;
                else 
                    head = c;
            } else {
                pp = p;
            }
            p = c;
        }
        c = c->next;
    }

    if (p->next != c) {
        if (pp)
            pp->next = c;
        else
            head = nullptr;
    }
    return head;
}

void driver() {
    linked_list<int> ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    
    std::cout << "list before deleting duplicates: ";
    ll.display();
    ll.head = deleteDuplicates(ll.head);
    std::cout << "list after deleting duplicates: ";
    ll.display();
}