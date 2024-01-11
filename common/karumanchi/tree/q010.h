#if !defined(q0010_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// Give an algorithm to find the height or depth of a binary tree.
int
heightOfBinaryTree(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(root->left.get());
    int rightHeight = heightOfBinaryTree(root->right.get());

    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}



#define q0010_h
#endif