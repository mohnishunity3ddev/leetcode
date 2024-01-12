#if !defined(q030_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

void
zigzagTraversal(itreenode *root)
{
    if(root == nullptr) {
        return;
    }

    int level = 1;
    queue<itreenode *> q{32, nullptr};
    stack<itreenode *> s{32};
    q.enqueue(root);
    q.enqueue(nullptr);
    std::cout << "start of level 1. ";
    std::cout << "Traversing level from left to right.\n";
    bool goingRight = true;

    while(!q.isEmpty()) {
        itreenode *curr = q.dequeue();

        if(curr == nullptr && !q.isEmpty()) {
            ++level;
            if(!goingRight) {
                while(!s.isEmpty()) {
                    itreenode *n = s.pop();
                    std::cout << n->val << ", ";
                }
            }
            goingRight = !goingRight;
            std::cout << "\nstart of level " << level << ". ";
            if(goingRight) {
                std::cout << "Traversing level from left to right.\n";
            } else {
                std::cout << "Traversing level from right to left.\n";
            }
            q.enqueue(nullptr);
        } else {
            if(curr != nullptr) {
                if(goingRight) {
                    std::cout << curr->val << ", ";
                } else {
                    s.push(curr);
                }
                if(curr->left) {
                    q.enqueue(curr->left);
                }
                if(curr->right) {
                    q.enqueue(curr->right);
                }
            }
        }

    }

    std::cout << "\n";
}

#define q030_h
#endif
