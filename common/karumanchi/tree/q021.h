#if !defined(q021_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

// Given a sum, find out if a path exists from the root to a leaf node which
// equals the given sum. the sum is the sum of all nodes in a root-to-leaf path.
bool
hasPathSum(itreenode *root, int sum)
{
    bool result = false;
    if(root == nullptr) {
        return false;
    }

    auto *left = root->left.get();
    auto *right = root->right.get();
    sum -= root->val;

    if (!left && !right) // leaf node.
    {
        result = (sum == 0);
    }
    else
    {
        result = hasPathSum(root->left.get(), sum);
        if(!result) {
            result = hasPathSum(root->right.get(), sum);
        }
    }

    return result;
}

#define q021_h
#endif
