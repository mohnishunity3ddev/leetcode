#if !defined(q0003_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>


// Search for element in a given binary tree.
bool
searchElementInBinaryTree(binary_tree_node<int> *root, int valueToFind)
{
    if(root == nullptr) {
        return false;
    }

    if(root->val == valueToFind) {
        return true;
    }

    if (searchElementInBinaryTree(root->left, valueToFind) ||
        searchElementInBinaryTree(root->right, valueToFind))
    {
        return true;
    } else {
        return false;
    }
}



#define q0003_h
#endif