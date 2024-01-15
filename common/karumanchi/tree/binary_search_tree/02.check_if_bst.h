#if !defined (CHECK_VERIFY_BST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

// NOTE: The idea here is that inorder traversal of a BST is ALWAYS a sorted
// list of numbers. As we go element by element in the inorder traversal, if we
// find an element which is smaller than its inorder predecessor, we know for
// sure that the given tree is not a binary search tree.
bool
isBST_InorderApproach(iBstNode *root)
{
    bool isBst = true;
    stack<iBstNode *> s{32};
    bool done = false;

    auto *curr = root;
    int inorderPredecessor = 1 << 31; // the lowest value an int can hold.

    while(!done) {
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            if(inorderPredecessor < curr->val) {
                inorderPredecessor = curr->val;
            } else {
                std::cout << "\nNOT a BST since we encountered " << curr->val
                          << " but the inorder predecessor was "
                          << inorderPredecessor << std::endl;
                isBst = false;
                break;
            }
            std::cout << curr->val << ", ";
            curr = curr->right;
        } else {
            done = true;
        }
    }

    return isBst;
}

// this is a much more expensive algorithm.
// Here, for each node we check if it is greater the max node of its
// leftSubtree. and is smaller than the min node of its right subtree.
bool
isBST_MinMaxApproach(iBstNode *root)
{
    stack<iBstNode *> s{32};
    bool done = false;
    iBstNode *curr = root;
    bool isBST = true;

    while(!done) {
        while(curr != nullptr) {
            // NOTE: finding the max in the left subtree.
            iBstNode *temp = curr->left;
            if(temp != nullptr) {
                while(temp->right != nullptr) {
                    temp = temp->right;
                }
                if(temp->val  > curr->val) {
                    // max node in the left subtree of the current node is
                    // greater than the current node value, therefore, this is
                    // not a BST!
                    std::cout
                        << "The max node " << temp->val
                        << " in the left subtree of the node " << curr->val
                        << " is greater than the current node. Not a BST!\n";
                    isBST = false;
                    break;
                }
            }

            // NOTE: finding the min in the right subtree.
            temp = curr->right;
            if(temp != nullptr) {
                while(temp->left != nullptr) {
                    temp = temp->left;
                }

                // min node in the right subtree of the current node is less
                // than the current node value, therefore this is not a BST!
                if(temp->val < curr->val) {
                    std::cout
                        << "The min node " << temp->val
                        << " in the right subtree of the node " << curr->val
                        << " is less than the current node. Not a BST!\n";
                    isBST = false;
                    break;
                }
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

    return isBST;
}

#define CHECK_VERIFY_BST_H
#endif // CHECK_VERIFY_BST_H