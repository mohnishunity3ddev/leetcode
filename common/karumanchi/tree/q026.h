#if !defined(q026_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

itreenode *
getNode(itreenode *root, int item)
{
    if(root == nullptr) {
        return nullptr;
    }

    if(root->val == item) {
        return root;
    }

    auto *node = getNode(root->left, item);
    if(!node) {
        node = getNode(root->right, item);
    }

    return node;
}

itreenode *
LCA(itreenode *root, itreenode *a, itreenode *b) {
    if(root == nullptr) {
        return nullptr;
    }

    if(root == a || root == b) {
        return root;
    }

    itreenode *left = LCA(root->left, a, b);
    itreenode *right = LCA(root->right, a, b);

    if(left && right) {
        return root;
    } else {
        if(left != nullptr) {
            return left;
        } else if(right != nullptr) {
            return right;
        } else {
            return nullptr;
        }
    }
}

// Least Common Ancestor
itreenode *
LCA(itreenode *root,  int a, int b)
{
    auto *nodeA = getNode(root, a);
    auto *nodeB = getNode(root, b);

    return LCA(root, nodeA, nodeB);
}

#define q026_h
#endif
