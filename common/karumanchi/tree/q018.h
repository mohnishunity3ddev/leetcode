#if !defined(q018_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

// diameter is the max distance between any two nodes of a tree which may or may
// not pass through the root.
int
diameter(itreenode *root, int *maxDiameterTillNow)
{
    if(root == nullptr) {
        return 0;
    }

    int leftDiameter = diameter(root->left.get(), maxDiameterTillNow);
    int rightDiameter = diameter(root->right.get(), maxDiameterTillNow);

    if((leftDiameter + rightDiameter) > *maxDiameterTillNow) {
        *maxDiameterTillNow = (leftDiameter + rightDiameter);
    }

    return (1 + std::max(leftDiameter, rightDiameter));
}

#define q018_h
#endif
