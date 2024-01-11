#if !defined(q024_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

std::unique_ptr<itreenode>
getBinaryTreeMirror(itreenode *root) {
    if(root == nullptr) {
        return nullptr;
    }

    auto newNode =
        std::make_unique<itreenode>(root->val,
                                    std::move(getBinaryTreeMirror(root->right.get())),
                                    std::move(getBinaryTreeMirror(root->left.get())));

        return newNode;
}

#define q024_h
#endif
