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
};
#define node ll_node<T>

template <typename T>
struct linked_list
{
    node *head = nullptr;
    i32 size = 0;

    linked_list() = default;
    ~linked_list();

    bool isEmpty();
    void add(T val);
    void removeAt(i32 index);
    void remove(T val);
    i32 getCount();
    void display();
    void clear();
};


#define LINKED_LIST_H
#endif // LINKED_LIST_H