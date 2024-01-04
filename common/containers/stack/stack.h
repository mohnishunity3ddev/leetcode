#if !defined(STACK_H)

#define LINKED_LIST_STACK 0
#include "defines.h"
#include <memory.h>
#include <cstdio>

template <typename T>
struct stack
{
    T *items;
    i32 top = -1;
    i32 capacity = 0;
    i32 size = 0;

    stack(i32 reserveCapacity)
    {
        items = new T[reserveCapacity];
        top = -1;
        size = 0;
        capacity = reserveCapacity;
    }

    stack() : stack(1) {}

    void
    push(T item)
    {
        if((size + 1) > capacity)
        {
            T *memory = new T[capacity*2];
            memcpy(memory, items, sizeof(T)*size);
            delete[] items;
            items = memory;
            capacity *= 2;
        }
        items[++top] = item;
        size += 1;
    }

    bool
    isEmpty()
    {
        bool result = top == -1;
        return result;
    }

    T
    pop()
    {
        if(isEmpty())
        {
            printf("The Stack is empty!\n");
            return -1;
        }
        T result = items[top--];
        return result;
    }

    ~stack()
    {
        delete[] items;
        items = nullptr;
        size = 0;
        capacity = 0;
        top = -1;
        printf("stack destructor called!\n");
    }
};

void
driver()
{
    stack<i32> myStack;
    myStack.push(-12);
    myStack.push(100);
    myStack.push(-100);
    printf("Stack Display:\n");
    for(i32 i = (myStack.size-1); i >= 0; --i)
    {
        printf("%d\n", *(myStack.items + i));
    }

    i32 p = myStack.pop();
    p = myStack.pop();
    p = myStack.pop();

    p = myStack.pop();
}

#define STACK_H
#endif // STACK_H