#if !defined(q016_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// half nodes are those nodes who have only one child.
int
countHalfNodes(itreenode *root, std::vector<int> &halfNodes)
{
    int result = 0;
    if(root == nullptr) {
        return result;
    }

    queue<itreenode *> q{32};
    q.enqueue(root);

    while(!q.isEmpty())
    {
        auto *curr = q.dequeue();

        auto *left = curr->left.get();
        auto *right = curr->right.get();

        if ((left != nullptr && right == nullptr) ||
            (left == nullptr && right != nullptr))
        {
            ++result;
            halfNodes.push_back(curr->val);
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

#define q016_h
#endif
