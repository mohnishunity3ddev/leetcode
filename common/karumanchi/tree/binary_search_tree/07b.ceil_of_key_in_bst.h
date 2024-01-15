#if !defined (CEIL_OF_KEY_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

// NOTE: if key is 8, then the ceil node will be the lowest value node which greater than or equal to key.
iBstNode *
ceil(iBstNode *root, int key)
{
    iBstNode *ceilNode = nullptr;
    if(root->val == key) {
        ceilNode = root;
        return ceilNode;
    }

    int ceiling = 0x7FFFFFFF; // lowest int.

    auto *curr = root;
    while(curr != nullptr) {
        // NOTE: this is a potential ceil node. Because we found a node whose
        // value is more than or equal to the key passed.
        if(curr->val >= key) {
            if(ceiling > curr->val) {
                ceiling = curr->val;
                ceilNode = curr;
            }
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return ceilNode;
}

void
ceilNode_test()
{
#if 0
    int origSize = Rand.next(2, 250);
    std::vector<int> randomSequence = Rand.getUniqueRandomSequence(0, origSize-1, 11);
    int size = randomSequence.size();
    int *arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = randomSequence[i];
    }

    binary_search_tree<int> bst{arr, size};
    bst.inorder();
    std::cout << "size of the BST is: " << size << ".\n";

    int key = Rand.next(1, origSize);
    iBstNode *ceilNode = ceil(bst.getRoot(), key);
    if(ceilNode != nullptr) {
        std::cout << "the ceil of the BST with key " << key
                  << " is: " << ceilNode->val << "\n";
    } else {
        std::cout << "No element found in the BST whose value is more than or "
                     "equal to " << key << ".\n";
    }
    std::cout << "-----------End of test-----------\n";
#endif
    int arr[] = {33,  11,  0,   22,  154, 110, 165, 77, 132, 187,
                 198, 176, 209, 143, 121, 88,  55,  44, 66,  99};
    int key = Rand.next(0, 210);
    binary_search_tree<int> bst{arr, ARRAY_SIZE(arr)};
    bst.inorder();
    iBstNode *ceilNode = ceil(bst.getRoot(), key);
    if(ceilNode != nullptr) {
        std::cout << "the ceil of the BST with key " << key
                  << " is: " << ceilNode->val << "\n";
    } else {
        std::cout << "No element found in the BST whose value is more than or "
                     "equal to " << key << ".\n";
    }

}

#define CEIL_OF_KEY_H
#endif // CEIL_OF_KEY_H