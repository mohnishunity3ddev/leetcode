#if !defined(q023_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

int
sumOfBinaryTreeIterative(itreenode *root) {
    if(root == nullptr) {
        return 0;
    }

    int sum = 0;
    queue<itreenode *> q{32, nullptr};

    q.enqueue(root);

    while(!q.isEmpty()) {
        auto *curr = q.dequeue();

        sum += curr->val;

        auto *left = curr->left;
        auto *right = curr->right;
        if(left) {
            q.enqueue(left);
        }
        if(right) {
            q.enqueue(right);
        }
    }

    return sum;
}



#define q023_h
#endif
