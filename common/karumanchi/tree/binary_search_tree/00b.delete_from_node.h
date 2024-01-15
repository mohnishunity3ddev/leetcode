#if !defined(DELETE_FROM_BST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
findMax(iBstNode *root)
{
    if(root == nullptr) {
        return nullptr;
    }

    if(root->right == nullptr) {
        return root;
    }

    return findMax(root->right);
}

iBstNode *
deleteFromBST(iBstNode *root, int data)
{
    iBstNode *temp = nullptr;
    if(root == nullptr) {
        return nullptr;
    }

    if(data < root->val) {
        // if node data is less than current root, then it must be in the root's
        // left subtree.
        root->left = deleteFromBST(root->left, data);
    } else if(data > root->val) {
        // if node data is more than current root, then it must be in the root's
        // right subtree.
        root->right = deleteFromBST(root->right, data);
    } else {
        // NOTE: Found element that we want to delete.
        // if the element to be deleted, has two children, then replace its
        // value with the largest node in its left subtree. and then call delete
        // on the left subtree to delete the max node.
        if(root->left && root->right) {
            // find max node in left subtree
            temp = findMax(root->left);
            // replace the deleted node with the max node value
            root->val = temp->val;
            // call delete on the left subtree deleting that max node.
            root->left = deleteFromBST(root->left, root->val);
        } else {
            // has only one child
            temp = root;
            // if the deleted element has no children, return nullptr.
            if(root->left == nullptr && root->right == nullptr) {
                root = nullptr;
            } else
            // if the deleted node has a right child, return the pointer to its right child.
            if(root->left == nullptr) {
                root = root->right;
            } else
            // if the deleted node has a left child, return the pointer to its left child.
            if(root->right == nullptr) {
                root = root->left;
            }
            // free the memory used by this deleted node.
            delete temp;
        }
    }

    return root;
}

iBstNode *
deleteFromBSTIterative(iBstNode *root, int data)
{
    iBstNode *current = root;
    iBstNode *parent = nullptr;

    // Search for the node to be deleted.
    while (current != nullptr && current->val != data) {
        parent = current;

        if (data < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // If the node with the given data is not found, return the original root.
    if (current == nullptr) {
        return root;
    }

    // Case: Node to be deleted has two children.
    if (current->left && current->right) {
        iBstNode *successor = current->right;
        iBstNode *successorParent = current;

        // Find the successor (smallest node in the right subtree).
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace the current node's value with the successor's value.
        current->val = successor->val;

        // Update current and parent for deletion.
        current = successor;
        parent = successorParent;
    }

    // Cases: Node to be deleted has zero or one child.
    iBstNode *child = (current->left != nullptr) ? current->left : current->right;

    // If the node to be deleted is the root.
    if (parent == nullptr) {
        root = child;
    } else if (parent->left == current) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    // Free the memory used by the deleted node.
    delete current;

    return root;
}

#define DELETE_FROM_BST_H
#endif