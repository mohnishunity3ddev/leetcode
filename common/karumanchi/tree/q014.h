#if !defined(q014_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

int
countLeaves(itreenode *root, std::vector<int> &leafNodes)
{
    int result = 0;
    if(root == nullptr) {
        return result;
    }

    queue<itreenode *> q{32, nullptr};
    q.enqueue(root);

    while(!q.isEmpty())
    {
        auto *curr = q.dequeue();

        auto *left = curr->left;
        auto *right = curr->right;

        if(left == nullptr && right == nullptr) {
            leafNodes.push_back(curr->val);
            ++result;
        }

        if(left) {
            q.enqueue(left);
        }
        if(right) {
            q.enqueue(right);
        }
    }

    return result;
}

#define q014_h
#endif
