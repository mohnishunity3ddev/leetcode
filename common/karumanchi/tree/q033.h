#if !defined(q033_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <math.h>

#include <iostream>

// NOTE: [QUESTION STATEMENT]
// Given a tree with a special property where leaves are represnted with 'L' and
// internal nodes with 'I'. Also, assume that each node has either 0 or 2
// children. Given preorder traversal of this tree, construct the tree.

itreenode *
buildBinaryTreeFromPreorder(const char *preOrderString, int i)
{
    itreenode *newNode = new itreenode(i);
    if(preOrderString[i] == 'L') {
        return newNode;
    }
    i += 1;
    newNode->left = buildBinaryTreeFromPreorder(preOrderString, i);
    i += 1;
    newNode->right = buildBinaryTreeFromPreorder(preOrderString, i);
    return newNode;
}

#define q033_h
#endif
