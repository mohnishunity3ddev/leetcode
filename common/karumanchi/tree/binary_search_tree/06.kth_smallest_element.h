#if !defined (KTH_SMALLEST_ELEMENT_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
kthSmallestElement(iBstNode *root, int k)
{
    ASSERT(k >= 1);

    stack<iBstNode *> s{32};
    bool done = false;
    auto *curr = root;
    int count = 1;

    iBstNode *result = nullptr;

    while(!done) {
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            if(count++ == k) {
                result = curr;
                break;
            }
            curr = curr->right;
        } else {
            done = false;
        }
    }

    return result;
}

void
kthSmallestElement_test()
{
    for (int index = 0; index < 50; ++index) {
        std::cout << "-----------Start of test " << (index + 1)
                  << ".-----------\n";
        int size = Rand.next(1, 250);
        std::vector<int> randomSequence = Rand.getUniqueRandomSequence(0, size-1);
        int *arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = randomSequence[i];
        }

        binary_search_tree<int> bst{arr, size};
        bst.inorder();
        std::cout << "size of the BST is: " << size << ".\n";

        int k = Rand.next(1, 10);
        iBstNode *kthSmallest = kthSmallestElement(bst.getRoot(), k);
        if(kthSmallest != nullptr) {
            std::cout << "The " << k
                    << "th smallest element in the BST is: " << kthSmallest->val
                    << "\n";
        } else {
            std::cout << "Could not find the kth smallest element in the BST\n";
        }
        std::cout << "-----------End of test " << (index + 1)
                  << ".-----------\n";
    }
}

#define KTH_SMALLEST_ELEMENT_H
#endif // KTH_SMALLEST_ELEMENT_H