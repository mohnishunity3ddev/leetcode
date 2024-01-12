#if !defined(q0005_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// insert an item into the first binary tree node whose right child is null
bool
insertAsRightChild(binary_tree_node<int> *root, int item)
{
    // pre-order

    stack<binary_tree_node<int> *> s{32};
    auto *curr = root;
    bool done = false;
    bool inserted = false;

    while(!done) {
        // get to the left most node
        while(curr != nullptr) {
            std::cout << curr->val << ", ";
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            if(curr->right == nullptr && !inserted) {
                auto node = new binary_tree_node<int>(item);
                curr->right = node;
                inserted = true;
            }
            curr = curr->right;
        } else {
            done = true;
        }
    }

    return inserted;
}



#define q0005_h
#endif