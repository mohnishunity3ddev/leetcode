#if !defined(q017_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

bool
areTreesStructurallyIdentical(itreenode *a, itreenode *b)
{
    if(a == nullptr && b == nullptr) {
        return true;
    }

    if(a == nullptr || b == nullptr) {
        return false;
    }

    return ((a->val == b->val) &&
            areTreesStructurallyIdentical(a->left, b->left) &&
            areTreesStructurallyIdentical(a->right, b->right));
}

#define q017_h
#endif
