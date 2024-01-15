#if !defined(INSERT_INTO_BST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
insertRecursive(iBstNode *root, int data)
{
    if(root == nullptr) {
        root = new iBstNode(data);
    } else {
        if(data < root->val) {
            root->left = insertRecursive(root->left, data);
        } else if(data > root->val) {
            root->right = insertRecursive(root->right, data);
        }
    }

    return root;
}

void
insertIterative(iBstNode **root, int data)
{
    if(*root == nullptr) {
        *root = new iBstNode(data);
        return;
    }

    iBstNode *newNode = new iBstNode(data);
    auto *curr = *root;
    while(curr != nullptr) {
        if(data < curr->val) {
            if(curr->left != nullptr) {
                curr = curr->left;
            } else {
                curr->left = newNode;
                break;
            }
        } else if(data > curr->val) {
            if(curr->right != nullptr) {
                curr = curr->right;
            } else {
                curr->right = newNode;
                break;
            }
        } else {
            break;
        }
    }
}

#define INSERT_INTO_BST_H
#endif