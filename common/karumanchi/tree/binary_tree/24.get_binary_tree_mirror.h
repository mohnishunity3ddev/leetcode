#if !defined(q024_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

itreenode *
getBinaryTreeMirror(itreenode *root) {
    if(root == nullptr) {
        return nullptr;
    }

    itreenode *newNode =
        new itreenode(root->val, getBinaryTreeMirror(root->right),
                      getBinaryTreeMirror(root->left));

    return newNode;
}

#define q024_h
#endif
