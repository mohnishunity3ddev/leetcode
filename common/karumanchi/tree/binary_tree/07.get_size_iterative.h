#if !defined(q0007_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// get the total number of items in the binary tree using in-order traversal
int
getSizeIterative(binary_tree_node<int> *root)
{
    int size = 0;
    stack<binary_tree_node<int> *> s{32};
    auto *curr = root;

    bool done = false;

    while(!done) {
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty())
        {
            curr = s.pop();
            size++;
            curr = curr->right;
        }
        else
        {
            done = true;
        }
    }

    return size;
}



#define q0007_h
#endif