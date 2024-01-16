#if !defined(STACK_H)

#define LINKED_LIST_STACK 0
#include "defines.h"
#include <memory.h>
#include <iostream>

template <typename T>
struct stack
{
  private:
    T *items;
    i32 top = -1;
    i32 capacity = 0;
    i32 size = 0;

  public:
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

    T
    peek()
    {
        if(isEmpty()) {
            return NULL;
        }

        T result = items[top];
        return result;
    }

    bool
    isEmpty()
    {
        bool result = top == -1;
        return result;
    }

    T
    pop(bool displayMsg = true)
    {
        if(isEmpty())
        {
            if(displayMsg) {
                printf("The Stack is empty!\n");
            }
            return 0;
        }
        T result = items[top--];
        size--;
        return result;
    }

    void display() {
        std::cout << "The stack is: \n";
        T *curr = items + top;
        for (i32 i = 0; i < size; ++i) {
            std::cout << *(curr--) << "\n";
        }
    }

    i32 getSize() {
        return size;
    }

    ~stack()
    {
        delete[] items;
        items = nullptr;
        size = 0;
        capacity = 0;
        top = -1;
    }
};

void
driver()
{
    stack<i32> myStack;
    myStack.push(-12);
    myStack.push(100);
    myStack.push(-100);
    myStack.display();

    i32 p = myStack.pop();
    p = myStack.pop();
    p = myStack.pop();

    p = myStack.pop();
}

#define STACK_H
#endif // STACK_H