#if !defined (RANGE_PRINTER_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

void
insertion(std::vector<int> &vec, int item)
{
    vec.push_back(item);
    if(vec.size() >= 2) {
        for (int i = vec.size()-1; i > 0; --i) {
            if(vec[i] < vec[i-1]) {
                int aXorB = vec[i] ^ vec[i-1];
                vec[i] ^= aXorB;
                vec[i-1] ^= aXorB;
            }
        }
    }
}

// NOTE: Given a range [k1, k2], print all elements/nodes in this bst which are
// within this range.
std::vector<int>
rangePrinterBst_LevelOrderApproach(iBstNode *root, int k1, int k2)
{
    std::vector<int> rangeElements;

    queue<iBstNode *> q{32, nullptr};
    auto *curr = root;
    q.enqueue(curr);

    while(!q.isEmpty()) {
        curr = q.dequeue();
        if(curr->val >= k1 && curr->val <= k2) {
            insertion(rangeElements, curr->val);
        }

        if(curr->left) {
            q.enqueue(curr->left);
        }
        if(curr->right) {
            q.enqueue(curr->right);
        }
    }

    return rangeElements;
}

std::vector<int>
rangePrinterBst_InOrderApproach(iBstNode *root, int k1, int k2)
{
    std::vector<int> rangeElements;

    stack<iBstNode *> s{32};
    auto *curr = root;
    bool done = false;

    while(!done) {
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.isEmpty()) {
            curr = s.pop();
            if(curr->val >= k1 && curr->val <= k2) {
                insertion(rangeElements, curr->val);
            } else if(curr->val > k2){
                // NOTE: We can safely break here since if we see one node with
                // value greater than k2, then every subsequent node will be
                // guaranteed to be greater than k2. So, no use traversing the
                // tree now.
                break;
            }
            curr = curr->right;
        } else {
            done = true;
        }
    }

    return rangeElements;
}

void
rangePrinter_test()
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

    int k1 = Rand.next(0, 210), k2 = Rand.next(k1, 210);
    auto rangeElements = rangePrinterBst_InOrderApproach(bst.getRoot(), k1, k2);

    std::cout << "elements between " << k1 << " and " << k2 << " are:\n";
    for(const auto &item : rangeElements) {
        std::cout << item << ", ";
    }

}

#define RANGE_PRINTER_H
#endif // RANGE_PRINTER_H