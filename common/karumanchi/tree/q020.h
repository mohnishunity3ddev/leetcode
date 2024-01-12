#if !defined(q020_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

void
printArray(int *arr, int size)
{
    std::cout << "START --> ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " --> ";
    }
    std::cout << " END.\n";
}

void
printRootToLeafPaths(itreenode *root, int path[], int pathLen) {
    if(root == nullptr) {
        return;
    }
    path[pathLen++] = root->val;

    auto *left = root->left;
    auto *right = root->right;
    if(left == nullptr && right == nullptr) {
        printArray(path, pathLen);
    } else{
        printRootToLeafPaths(left, path, pathLen);
        printRootToLeafPaths(right, path, pathLen);
    }
}

#define q020_h
#endif
