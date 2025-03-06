#pragma once

#include <containers/linked_list/linked_list.h>

inline void printList(ListNode *h) {
    ListNode *c = h;
    std::cout << '[';
    while (c != nullptr) {
        std::cout << c->val << ", ";
        c = c->next;
    }
    std::cout << "\b\b]\n";
}

inline ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy{3};
    ListNode *p = &dummy;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1) {
        p->next = list1;
    } else {
        p->next = list2;
    }

    ListNode *head = dummy.next;
    return dummy.next;
}

inline void driver() {
    linked_list<int> list1;
    list1.add(1); list1.add(2); list1.add(4);
    printList(list1.head);
    linked_list<int> list2;
    list2.add(1);
    list2.add(3);
    list2.add(4);
    printList(list2.head);

    ListNode *merged = mergeTwoLists(list1.head, list2.head);
    printList(merged);
    int x = 0;
}