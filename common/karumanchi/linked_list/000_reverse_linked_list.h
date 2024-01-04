#if !defined(reverse_linked_list_h)

#include "defines.h"
#include <containers/linked_list/linked_list.h>
#include <containers/stack/stack.h>
#include <iostream>

class solution {
  public:

    void
    reverse(linked_list<i32> *list)
    {
        ll_node<i32> *p = nullptr, *temp = nullptr;
        ll_node<i32> *c = list->head;

        while(c != nullptr) {
            p = c;
            c = c->next;
            p->next = temp;
            temp = p;
        }

        list->head = p;
    }

    void
    reverseUsingStack(linked_list<i32> *list)
    {
        std::cout << "original list is: \n";
        list->display();

        stack<i32> stack(list->size);
        ll_node<i32> *curr = list->head;

        while (curr != nullptr)
        {
            stack.push(curr->value);
            curr = curr->next;
        }

        for (i32 i = 0; i < list->size; ++i)
        {
            i32 top = stack.pop();
            list->update(i, top);
        }

        list->display();
    }

    void
    driver()
    {
        linked_list<i32> ll;
        getRandomList<i32>(&ll, 5);

        std::cout << "original list:\n";
        ll.display();

        solution sol;
        sol.reverse(&ll);

        std::cout << "list after reverse:\n";
        ll.display();
    }

};

#define reverse_linked_list_h
#endif