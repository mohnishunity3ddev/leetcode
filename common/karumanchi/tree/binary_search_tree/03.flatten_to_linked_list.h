#if !defined (FLATTEN_TO_LINKED_LIST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
FlattenBSTRecursive(iBstNode *root)
{
    static iBstNode *prev = nullptr;

    if(root == nullptr) {
        return nullptr;
    }

    FlattenBSTRecursive(root->right);
    FlattenBSTRecursive(root->left);

    root->left = nullptr;
    root->right = prev;
    if(prev != nullptr) {
        prev->left = root;
    }
    prev = root;

    return root;
}

iBstNode *
FlattenBSTIterative(iBstNode *root)
{
    if(root == nullptr) {
        return nullptr;
    }

    stack<iBstNode *> s{32};
    iBstNode *curr = root;

    iBstNode *prev = nullptr;

    // NOTE: Reverse PostOrder. Right-Left-Parent
    do
    {
        while(curr != nullptr) {
            if(curr->left) {
                s.push(curr->left);
            }
            s.push(curr);
            curr = curr->right;
        }

        curr = s.pop();

        if(curr->left != nullptr && s.peek() == curr->left) {
            s.pop();
            s.push(curr);
            curr = curr->left;
        } else {
            // NOTE: This is the place where we actually start visiting the node
            // while traversing the tree.

            // IMPORTANT: this is where the flattening is actually happening.
            curr->right = prev;
            if(prev) {
                prev->left = curr;
            }
            prev = curr;

            // std::cout << curr->val << ", ";
            curr = nullptr;
        }
    } while (!s.isEmpty());

    root->left = nullptr;
    return root;
}

void FlattenBST_Test() {

    int arr[] = {8, 4, 2, 3, 1, 6, 5, 11, 10, 12};
    binary_search_tree<int> bst{arr, ARRAY_SIZE(arr)};

#if 0
    auto *head = BSTtoDLLRecursive(bst.getRoot());
    int count = 0;
    while(head->right != nullptr) {
        std::cout << head->val << " --> ";
        ASSERT(hasItem(arr, ARRAY_SIZE(arr), head->val));
        head = head->right;
    }
    std::cout << head->val << "." << std::endl;
    while(head->left != nullptr) {
        std::cout << head->val << " --> ";
        ASSERT(hasItem(arr, ARRAY_SIZE(arr), head->val));
        head = head->left;
    }
    std::cout << head->val << "." << std::endl;
#endif
    auto *t = FlattenBSTIterative(bst.getRoot());
    while (t->right != nullptr)
    {
        std::cout << t->val << ", ";
        t = t->right;
    }
    std::cout << t->val << ".\n";
    while (t->left != nullptr)
    {
        std::cout << t->val << ", ";
        t = t->left;
    }
    std::cout << t->val << ".\n";
}

#define FLATTEN_TO_LINKED_LIST_H
#endif // FLATTEN_TO_LINKED_LIST_H