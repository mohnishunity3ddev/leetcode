#if !defined(q011_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// Give an algorithm to find the height or depth of a binary tree without using
// recursion.
int
heightOfBinaryTree(binary_tree_node<int> *root)
{
    int height = 0;
    queue<binary_tree_node<int> *> q(32);
    queue<binary_tree_node<int> *> auxQ(32);
    

    q.enqueue(root);
    std::cout << root->val << ", " << std::endl;

    while(!q.isEmpty() || !auxQ.isEmpty()) {

        if(q.isEmpty()) {
            while(!auxQ.isEmpty()) {
                auto *t = auxQ.dequeue();
                if(t != nullptr) {
                    std::cout << t->val << ", ";
                }
                q.enqueue(t);
            }
            std::cout << std::endl;
        }

        auto *curr = q.dequeue();
        if(q.isEmpty()) {
            height++;
        }

        auto *left = curr->left.get();
        auto *right = curr->right.get();
        if (left) { auxQ.enqueue(left); }
        if (right) { auxQ.enqueue(right); }
    }

    return height;
}

int karu_height(binary_tree_node<int> *root) {
    int level = 1;
    queue<binary_tree_node<int> *> q{32};

    if(root == nullptr) { return 0; }

    q.enqueue(root);
    q.enqueue(nullptr);

    while(!q.isEmpty()) {
        root = q.dequeue();

        if(root == nullptr) {
            if(!q.isEmpty()) {
                q.enqueue(nullptr);
            }
            level++;
        } else {
            if (root->left.get()) { q.enqueue(root->left.get()); }
            if (root->right.get()) { q.enqueue(root->right.get()); }
        }
    }

    return level;
}



#define q011_h
#endif