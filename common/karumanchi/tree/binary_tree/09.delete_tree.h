#if !defined(q0009_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

// Write a function to delete the tree.
// post-order makes sense here -  since, before deleting a node we need to
// delete both its child nodes.
void
clearTree(binary_tree_node<int> *root)
{
    std::cout << "Clearing tree iteratively. Post-Order Traversal.\n";

    stack<binary_tree_node<int> *> s{32};
    auto *curr = root;

    do
    {
        while(curr != nullptr) {
            if(curr->right) {
                s.push(curr->right);
            }
            s.push(curr);
            curr = curr->left;
        }

        curr = s.pop();

        if(curr->right != nullptr && curr->right == s.peek()) {
            s.pop();
            s.push(curr);
            curr = curr->right;
        } else {
            std::cout << curr->val
                      << " should be destroyed at index: " << curr->arrIndex
                      << std::endl;
            curr = nullptr;
        }


    } while (!s.isEmpty());
}

void
clearTreeRecursive(binary_tree_node<int> *root)
{
    if(root == nullptr) {
        return;
    }

    clearTreeRecursive(root->left);
    clearTreeRecursive(root->right);
    std::cout << root->val
              << " should be destroyed recursively at index: " << root->arrIndex
              << std::endl;
}



#define q0009_h
#endif