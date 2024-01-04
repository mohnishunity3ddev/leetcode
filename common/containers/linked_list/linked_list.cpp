#include "linked_list.h"

template<typename T>
linked_list<T>::~linked_list() { clear(); }

template <typename T>
bool
linked_list<T>::isEmpty()
{
    bool result = ((head == nullptr) && (size == 0));
    return result;
}

template <typename T>
void
linked_list<T>::add(T val)
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

template <typename T>
void
linked_list<T>::removeAt(i32 index)
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

    T val = c->value;
    node *n = c;
    p->next = c->next;
    delete n;
    size--;

    std::cout << "removed " << val << "\n";
    display();
}

template <typename T>
void
linked_list<T>::remove(T val)
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
        printf("%d not found.\n");
        return;
    }

    node *n = c;
    p->next = c->next;
    delete n;
    size--;

    std::cout << "removed " << val << "\n";
    display();
}

template <typename T>
i32
linked_list<T>::getCount()
{
    return size;
}

template <typename T>
void
linked_list<T>::display()
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

template <typename T>
void
linked_list<T>::clear()
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
