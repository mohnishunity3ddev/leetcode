#if !defined(q0002_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// max element in a binary tree without using recursion
// NOTE: using Level Order
int
maxElementIterative(binary_tree_node<int> *root)
{
    int max = 1 << 31;

    queue<binary_tree_node<int> *> q{32};

    q.enqueue(root);

    while(!q.isEmpty())
    {
        auto *curr = q.dequeue();

        if(curr != nullptr) {
            if(curr->val > max) {
                max = curr->val;
            }

            auto *left = curr->left.get();
            auto *right = curr->right.get();
            if(left) { q.enqueue(left); }
            if(right) { q.enqueue(right); }
        }
    }

    return max;
}



#define q0002_h
#endif