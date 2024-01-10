#if !defined(q0004_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// Search for element in a given binary tree without using recursion
bool
searchElementInBinaryTree(binary_tree_node<int> *root, int valueToFind)
{
    bool result = false;

    stack<binary_tree_node<int> *> s{32};
    auto *curr = root;

    bool done = false;
    while(!done) {
        while(curr != nullptr) {
            if(curr->val == valueToFind) {
                result = true;
                break;
            } else {
                std::cout << curr->val << ", ";
                s.push(curr);
                curr = curr->left.get();
            }
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            curr = curr->right.get();
        } else {
            done = true;
        }

    }

    return result;
}



#define q0004_h
#endif