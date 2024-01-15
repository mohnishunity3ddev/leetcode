#if !defined (FLOOR_OF_KEY_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

// NOTE: if key is 8, then the largest item in the BST whose value is less than
// or equal to 8 is the floor.
iBstNode *
floorOfBst(iBstNode *root, int key)
{
    iBstNode *floorNode = nullptr;
    if(root->val == key) {
        floorNode = root;
        return floorNode;
    }

    int floor = 1 << 31;

    auto *curr = root;
    while(curr != nullptr) {
        // NOTE: this is a potential floor node. Because we found a node whose
        // value is less than the key passed/ if the current node value is less
        // than the key, we need to search in the right subtree.
        if(curr->val <= key) {
            if(floor < curr->val) {
                floor = curr->val;
                floorNode = curr;
            }
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    return floorNode;
}

void floorNode_test() {
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
    iBstNode *floorNode = floorOfBst(bst.getRoot(), key);
    if(floorNode != nullptr) {
        std::cout << "the floor of the BST with key " << key
                  << " is: " << floorNode->val << "\n";
    } else {
        std::cout << "No element found in the BST whose value is less than or "
                     "equal to " << key << ".\n";
    }
    std::cout << "-----------End of test-----------\n";
}

#define FLOOR_OF_KEY_H
#endif // FLOOR_OF_KEY_H