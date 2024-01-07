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
        // std::cout << "destructor for node value " << value << " called!\n";
    }
};
#define node ll_node<T>

template <typename T>
struct linked_list
{
    node *head = nullptr;
    node *tail = nullptr;
    i32 size = 0;

    linked_list() = default;
    ~linked_list()
    {
        std::cout << "destructor for linked list called!\n";
        clear();
    }

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
            tail = head;
        }
        else
        {
            ASSERT(tail != nullptr && tail->next == nullptr);
            tail->next = n;
            tail = n;
            size++;
        }
    }

    void addAt(i32 index, T val) {
        if (index >= size || index < 0)
        {
            std::cout << "Out of bounds access. The list has only " << size
                      << " items and you are trying to access " << index
                      << " index.\n";
            return;
        }
        node *n = new node(val);
        if(index == 0) {
            n->next = head;
            head = n;
            return;
        }

        node *c = head;
        node *p = c;
        for (i32 i = 0; i < index; ++i) {
            p = c;
            c = c->next;
        }

        p->next = n;
        n->next = c;
    }

    void update(i32 index, T val) {
        if (index >= size || index < 0)
        {
            std::cout << "Out of bounds access. The list has only " << size
                      << " items and you are trying to access " << index
                      << " index.\n";
            return;
        }

        node *c = head;
        for(i32 i = 0; i < index; ++i) {
            c = c->next;
        }
        ASSERT(c != nullptr);
        c->value = val;
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

        // special case for advancing head.
        if(index == 0)
        {
            node *n = head;
            head = head->next;
            T value = n->value;
            delete n;
            size--;
            if(head == nullptr)
            {
                tail = nullptr;
            }
            return;
        }

        node *c = head;
        node *p = c;
        for (i32 i = 0; i < index; ++i)
        {
            p = c;
            c = c->next;
        }

        T val = c->value;
        node *n = c;
        p->next = c->next;
        delete n;
        size--;
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

        // std::cout << "removed " << val << "\n";
        // display();
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
        // std::cout << "list with size " << size << " is ";
        std::cout << "Head";
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

template <typename T>
void
getRandomList(linked_list<T> *ll, i32 nItems)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<T> distribution(1, 20);

    for (i32 i = 0; i < nItems; ++i)
    {
        i32 n = distribution(gen);
        ll->add(n);
    }
}

#define LINKED_LIST_H
#endif // LINKED_LIST_H