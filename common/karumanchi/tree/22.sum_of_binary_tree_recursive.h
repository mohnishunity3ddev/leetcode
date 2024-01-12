#if !defined(q022_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

int
sumOfBinaryTreeRecur(itreenode *root) {
    if(root == nullptr) {
        return 0;
    }

    return root->val + sumOfBinaryTreeRecur(root->left) +
           sumOfBinaryTreeRecur(root->right);
}



#define q022_h
#endif
