#if !defined (BST_LEAST_COMMON_ANCESTOR_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

bool
nodeExists(iBstNode *root, int i)
{
    if(root == nullptr) {
        return false;
    }

    if(root->val == i) {
        return true;
    }

    return nodeExists(root->left, i) || nodeExists(root->right, i);
}

// NOTE: The LCA of two nodes in a BST, is the first node element we see in the
// preorder traversal of this bst whose value is between a and b
iBstNode *
LCA(iBstNode *root, int a, int b)
{
    // verify that nodes with value a and b exist.
    bool aExists = nodeExists(root, a);
    if(!aExists) {
        std::cout << "No node with value " << a << " exists in the BST.\n";
        return nullptr;
    }
    bool bExists = nodeExists(root, b);
    if(!bExists) {
        std::cout << "No node with value " << b << " exists in the BST.\n";
        return nullptr;
    }

    // preorder
    stack<iBstNode *> s{32};
    bool done = false;
    auto *curr = root;

    iBstNode *LCA = nullptr;

    while(!done) {
        while(curr != nullptr) {
            int data = curr->val;
            // std::cout << data << ", ";
            if((data >= a && data <= b) || (data >= b && data <= a))
            {
                LCA = curr;
                break;
            }

            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            curr = curr->right;
        } else {
            done = true;
        }
    }

    return LCA;
}

#define BST_LEAST_COMMON_ANCESTOR_H
#endif // BST_LEAST_COMMON_ANCESTOR_H