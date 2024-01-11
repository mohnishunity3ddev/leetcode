#if !defined(q012_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

#define ITERATIVE_DEEPEST_NODE 1

#if ITERATIVE_DEEPEST_NODE

binary_tree_node<int> *
deepestNode(binary_tree_node<int> *root)
{
    if(root== nullptr) {
        return nullptr;
    }

    queue<binary_tree_node<int> *> q{32};
    q.enqueue(root);

    binary_tree_node<int> *result = nullptr;

    while(!q.isEmpty())
    {
        result = q.dequeue();

        if(result->left.get()) {
            q.enqueue(result->left.get());
        }
        if(result->right.get()) {
            q.enqueue(result->right.get());
        }
    }

    return result;
}

#else

int
height(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return 0;
    }

    int left = height(root->left.get());
    int right = height(root->right.get());

    if(left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}


binary_tree_node<int> *
deepestNode(binary_tree_node<int> *root, int height) {
    if(height == 0 && root != nullptr) {
        return root;
    } else if(root == nullptr) {
        return nullptr;
    }

    auto *left = deepestNode(root->left.get(), height - 1);
    auto *right = deepestNode(root->right.get(), height - 1);

    if(left != nullptr) {
        return left;
    }
    if(right != nullptr) {
        return right;
    }

    return nullptr;
}

binary_tree_node<int> *
deepestNode(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return nullptr;
    }

    int h = height(root);
    return deepestNode(root, h-1);
}
#endif

#define q012_h
#endif
