#if !defined(q0006_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// get the total number of items in the binary tree using recursion
int
getSize(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return 0;
    }
    else {
        int left = getSize(root->left);
        int right = getSize(root->right);
        int result = left + right + 1;
        return result;
    }
}



#define q0006_h
#endif