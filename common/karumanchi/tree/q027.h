#if !defined(q027_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

void
q27_displayVec(std::vector<int> &vec)
{
    for(auto item : vec) {
        std::cout << item << ", ";
    }
}

void
q27_inorder(itreenode *root, std::vector<int> &inorderVec)
{
    if(root == nullptr) {
        return;
    }

    stack<itreenode *> s{32};
    bool done = false;
    auto *curr = root;

    while(!done) {
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            inorderVec.push_back(curr->val);

            curr = curr->right;
        } else {
            done = true;
        }
    }
}

void
q27_preorder(itreenode *root, std::vector<int> &postorderVec)
{
    if (root == nullptr) {
        return;
    }

    stack<itreenode *> s{32};
    auto *curr = root;
    bool done = false;

    while(!done) {
        while(curr != nullptr) {
            postorderVec.push_back(curr->val);
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
}

int search(int *arr, int start, int end, int data) {
    for (int i = start; i <= end; ++i) {
        if(arr[i] == data) {
            return i;
        }
    }

    return -1;
}

// the first element in the preorder traversal array represents the root of the
// tree. We search for this item in the inorder traversal. the left of this
// index in the inorder array represents everything in the tree that is to the
// left of this node in the tree. To the right of this in inorder array
// represents everything to the right of this node in the tree. We recursively
// do the same thing to get the whole tree.
itreenode *
buildTree(int *inOrder, int *preOrder, int inorderStart, int inorderEnd)
{
    static int preIndex = 0;
    itreenode *newNode;
    
    if(inorderStart > inorderEnd) {
        return nullptr;
    }

    newNode = new itreenode();
    // select current node from preorder traversal using preIndex.
    newNode->val = preOrder[preIndex++];

    // if this node has no children then return.
    if(inorderStart == inorderEnd) {
        return newNode;
    }

    // find the index of this node in inOrder traversal.
    int inIndex = search(inOrder, inorderStart, inorderEnd, newNode->val);

    // Using index in inorder traversal, construct left and right subtrees.
    newNode->left = buildTree(inOrder, preOrder, inorderStart, inIndex - 1);
    newNode->right = buildTree(inOrder, preOrder, inIndex + 1, inorderEnd);
    return newNode;
}

itreenode *
buildTreeFromInorderPreorder(std::vector<int> inorder,
                             std::vector<int> preorder)
{
    std::cout << "\nInorder Traversal: \n";
    q27_displayVec(inorder);
    std::cout << "\nPreorder Traversal: \n";
    q27_displayVec(preorder);
    std::cout << "\n";



    // IMPORTANT: NOTE:
    // the first element in preorder gives the root of the tree.
    //
    // we search for this element in inorder, all elements to the left of this
    // element is the left subtree, all elements to the right is the right
    // subtree.

    return buildTree(inorder.data(), preorder.data(), 0, inorder.size()-1);
}

#define q027_h
#endif
