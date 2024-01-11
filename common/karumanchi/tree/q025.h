#if !defined(q025_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

bool
areMirrorTrees(itreenode *a, itreenode *b) {
    if((!a && !b)) {
        return true;
    }

    if((!a && b) || (a && !b)) {
        return false;
    }

    if(a->val == b->val) {
        return true;
    } else {
        return false;
    }

    return ((areMirrorTrees(a->left.get(), b->right.get()) &&
             areMirrorTrees(a->right.get(), b->left.get())));
}

#define q025_h
#endif
