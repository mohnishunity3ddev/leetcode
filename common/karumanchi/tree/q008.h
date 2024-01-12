#if !defined(q0008_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// print the level order data in reverse order
void
reverseLevelOrder(binary_tree_node<int> *root)
{
    queue<binary_tree_node<int> *> q{32, nullptr};
    stack<int> s{32};

    q.enqueue(root);

    while(!q.isEmpty()) {
        auto *curr = q.dequeue();

        s.push(curr->val);

        auto *left = curr->left;
        auto *right = curr->right;
        if(left != nullptr) {
            q.enqueue(left);
        }
        if(right != nullptr) {
            q.enqueue(right);
        }
    }

    std::cout << "Level order in reverse order is: \n";
    while(!s.isEmpty()) {
        int n = s.pop();
        std::cout << n << ", ";
    }
}



#define q0008_h
#endif