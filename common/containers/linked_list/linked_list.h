#if !defined(LINKED_LIST_H)

#include "defines.h"
#include <iostream>

template <typename T>
struct ll_node
{
    T value;
    ll_node *next;

    ll_node(T  value) {
        this->value = value;
        this->next = nullptr;
    }

    ll_node(T val, ll_node *nextPtr) {
        this->value = val;
        this->next = nextPtr;
    }

    ~ll_node() {
        std::cout << "destructor for node value " << value << " called!\n";
    }
};
#define node ll_node<T>

template <typename T>
struct linked_list
{
    node *head = nullptr;
    i32 size = 0;

    linked_list() = default;
    ~linked_list() { clear(); }

    bool
    isEmpty()
    {
        bool result = ((head == nullptr) && (size == 0));
        return result;
    }

    void
    add(T val)
    {
        node *n = new node(val);
        if (isEmpty())
        {
            head = n;
            size = 1;
        }
        else
        {
            node *t = head;
            while (t->next != nullptr)
            {
                t = t->next;
            }
            t->next = n;
            size++;
        }

        std::cout << "added " << val << "\n";
        display();
    }

    void
    removeAt(i32 index)
    {
        if (index >= size || index < 0)
        {
            std::cout << "Out of bounds access. The list has only " << size
                      << " items and you are trying to access " << index
                      << " index.\n";
            return;
        }

        node *c = head;
        node *p = c;
        for (i32 i = 0; i < index; ++i)
        {
            p = c;
            c = c->next;
        }

        f32 val = c->value;
        node *n = c;
        p->next = c->next;
        delete n;
        size--;

        std::cout << "removed " << val << "\n";
        display();
    }

    void
    remove(T val)
    {
        node *c = head;
        node *p = c;

        while (c != nullptr && c->value != val)
        {
            p = c;
            c = c->next;
        }

        if (c == nullptr)
        {
            std::cout << val << " not found.\n";
            return;
        }

        node *n = c;
        p->next = c->next;
        delete n;
        size--;

        std::cout << "removed " << val << "\n";
        display();
    }

    i32
    getCount()
    {
        return size;
    }

    void
    display()
    {
        if (isEmpty())
        {
            std::cout << "the list is empty!\n";
            return;
        }
        std::cout << "list with size " << size << " is ";
        node *c = head;
        while (c != nullptr)
        {
            std::cout << " ==> " << c->value;
            c = c->next;
        }
        std::cout << " ==> end.\n\n";
    }

    void
    clear()
    {
        node *c = head;
        while (c != nullptr)
        {
            node *n = c;
            c = c->next;
            delete n;
        }
        size = 0;
        head = nullptr;
    }

};

void driver();
void exampleWithRandoms();

#define LINKED_LIST_H
#endif // LINKED_LIST_H