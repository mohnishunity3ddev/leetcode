#if !defined(q0001_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// max element in a binary tree
int
maxElementRecursive(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return (1 << 31);
    }

    int rootValue = root->val;
    int leftVal = maxElementRecursive(root->left);
    int rightVal = maxElementRecursive(root->right);

    int max = leftVal > rightVal ? leftVal : rightVal;
    max = rootValue > max ? rootValue : max;

    return max;
}



#define q0001_h
#endif