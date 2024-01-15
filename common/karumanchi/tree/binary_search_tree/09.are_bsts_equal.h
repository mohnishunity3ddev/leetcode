#if !defined (ARE_BSTS_EQUAL_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

bool
areBstsEqual(iBstNode *root1, iBstNode *root2)
{
    bool result = true;

    stack<iBstNode *> s1{32};
    stack<iBstNode *> s2{32};
    auto *curr1 = root1, *curr2 = root2;
    bool done = false;

    std::vector<int> b1;
    std::vector<int> b2;

    while(!done) {
        while(curr1 != nullptr) {
            s1.push(curr1);
            curr1 = curr1->left;
        }

        if(!s1.isEmpty()) {
            curr1 = s1.pop();
            b1.push_back(curr1->val);
            curr1 = curr1->right;
        } else {
            done = true;
        }
    }
    done = false;
    while(!done) {
        while(curr2 != nullptr) {
            s2.push(curr2);
            curr2 = curr2->left;
        }

        if(!s2.isEmpty()) {
            curr2 = s2.pop();
            b2.push_back(curr2->val);
            curr2 = curr2->right;
        } else {
            done = true;
        }
    }

    if(b1.size() != b2.size()) {
        result = false;
    } else {
        for(size_t i = 0; i < b1.size(); ++i) {
            if(b1[i] != b2[i]) {
                result = false;
                break;
            }
        }
    }


    return result;
}

void
areBstsEqual_test()
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
    std::vector<int> arr1 = {33,  11,  0,   22,  154, 110, 165, 77, 132, 187,
                            198, 176, 209, 143, 121, 88,  55,  44, 66,  99};
    binary_search_tree<int> bst1{arr1.data(), arr1.size()};

    std::random_device rd;
    std::mt19937 gen = std::mt19937(rd());
    std::vector<int> arr2 = arr1;
    std::shuffle(arr2.begin(), arr2.end(), gen);
    binary_search_tree<int> bst2{arr2.data(), arr2.size()};

    bool areEqual = areBstsEqual(bst1.getRoot(), bst2.getRoot());
    if(areEqual) {
        std::cout << "the two given BSTs are equal!\n";
    } else {
        std::cout << "the two given BSTs are NOT equal!\n";
    }
}

#define ARE_BSTS_EQUAL_H
#endif // ARE_BSTS_EQUAL_H