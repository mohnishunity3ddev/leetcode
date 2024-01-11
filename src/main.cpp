#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <karumanchi/tree/q024.h>
#include <karumanchi/tree/q025.h>

using namespace std;

void
printRootToItemPath(binary_tree_node<int> *root, int item)
{
    // post-order
    stack<binary_tree_node<int> *> s{32};
    std::vector<int> path;

    bool found = false;
    auto *curr = root;

    do {
        while(curr != nullptr) {
            if(curr->right.get()) {
                s.push(curr->right.get());
            }
            s.push(curr);
            curr = curr->left.get();
        }

        curr = s.pop();
        if(curr->val == item) {
            found = true;
            break;
        }

        if(curr->right.get() && s.peek() == curr->right.get()) {
            s.pop();
            s.push(curr);
            curr = curr->right.get();
        }
        else {
            curr = nullptr;
        }
    } while (!s.isEmpty());

    if(found) {
        binary_tree_node<int> *prev;
        bool done = false;
        while(!done) {
            // std::cout << curr->val << " <-- ";
            path.push_back(curr->val);
            if(curr->right.get() && curr->right.get() == s.peek()) {
                s.pop();
            }
            prev = curr;
            if(!s.isEmpty()) {
                curr = s.pop();
                if(curr->right.get() == prev) {
                    path.push_back(1);
                } else {
                    path.push_back(-1);
                }
            } else {
                curr = nullptr;
                done = true;
            }
        }
        if(curr) {
            path.push_back(curr->val);
        }
    } else {
        std::cout << "could not find the element!\n";
    }

    if(path.size() > 0) {
        for(int i = path.size() - 1; i >= 0; i -= 2) {
            std::cout << "(" << path[i];
            if(i > 0) {
                std::cout << ") --> [";
                int dir = path[i - 1];
                ASSERT(dir == 1 || dir == -1);
                if(dir == -1) {
                    std::cout << "left";
                } else if(dir == 1) {
                    std::cout << "right";
                }
                std::cout << "] --> ";
            }
        }
        std::cout << ").\n";
    }
}

int
main()
{
#if 0
    // int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, NULL, 301, 3123, NULL, 601, 701, NULL,
    //              NULL, 21, NULL, NULL, 39};

    // left-skewed tree
    // int arr[] = {8, 3, NULL, 5, NULL, NULL, NULL, 7};

    // right-skewed tree
    // int arr[] = {8,    NULL, 3,    NULL, NULL, NULL, 2, NULL,
    //              NULL, NULL, NULL, NULL, NULL, NULL, 1};

    int arr[] = {8, 3, 5, 4, 9, 11, 21};
    ibt binaryTree(arr, ARRAY_SIZE(arr));
#else
    // another example tree to test.

    auto twelve = std::make_unique<itreenode>(12);
    auto eleven = std::make_unique<itreenode>(11);
    auto ten = std::make_unique<itreenode>(10, nullptr, std::move(eleven));
    auto nine = std::make_unique<itreenode>(9, nullptr, std::move(ten));
    auto eight = std::make_unique<itreenode>(8, std::move(nine), std::move(twelve));
    auto four = std::make_unique<itreenode>(4, nullptr, std::move(eight));
    auto twenty = std::make_unique<itreenode>(20);
    auto three = std::make_unique<itreenode>(3, std::move(four), std::move(twenty));
    auto six = std::make_unique<itreenode>(6);
    auto seven = std::make_unique<itreenode>(7);
    auto two = std::make_unique<itreenode>(2, std::move(six), std::move(seven));
    auto one = std::make_unique<itreenode>(1, std::move(two), std::move(three));
    binary_tree<int> binaryTree(std::move(one));

 #endif

    auto mirrorRoot = getBinaryTreeMirror(binaryTree.getRoot());
    mirrorRoot->val = 312;
    ibt mirrorTree(std::move(mirrorRoot));
    int arr[] = {8, 3, 5, 4, 9, 11, 21};
    ibt binaryTree2(arr, ARRAY_SIZE(arr));

#if 0
    // 11 is a leaf node. We check if its a mirror by printing out the path from
    // root to this 11 node.
    printRootToItemPath(binaryTree.getRoot(), 11);
    printRootToItemPath(mirrorTree.getRoot(), 11);
    binary_tree_traversal<int>::postorderRecursive(binaryTree.getRoot());
    std::cout << "\n";
    binary_tree_traversal<int>::postorderRecursive(mirrorTree.getRoot());
    std::cout << "\n";
#endif

    bool areMirrors =
        areMirrorTrees(binaryTree.getRoot(), mirrorTree.getRoot());
    if(areMirrors) {
        std::cout << "Given trees are mirrors!\n";
    } else {
        std::cout << "Given trees are NOT mirrors!\n";
    }

}
