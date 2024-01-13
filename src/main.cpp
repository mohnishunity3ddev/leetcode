#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>

#include <karumanchi/tree/binary_search_tree/01.insert_into_bst.h>
#include <karumanchi/tree/binary_search_tree/02.delete_from_bst.h>

using namespace std;

struct test{

  private:
    int x;
    int y;

  public:
    static const int i = 10;
    test(int x, int y) : x(x) , y(y) {}
    int z;
};

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
            if(curr->right) {
                s.push(curr->right);
            }
            s.push(curr);
            curr = curr->left;
        }

        curr = s.pop();
        if(curr->val == item) {
            found = true;
            break;
        }

        if(curr->right && s.peek() == curr->right) {
            s.pop();
            s.push(curr);
            curr = curr->right;
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
            if(curr->right && curr->right == s.peek()) {
                s.pop();
            }
            prev = curr;
            if(!s.isEmpty()) {
                curr = s.pop();
                if(curr->right == prev) {
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
#if 1
    // int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, NULL, 301, 3123, NULL, 601, 701, NULL,
    //              NULL, 21, NULL, NULL, 39};

    // left-skewed tree
    // int arr[] = {8, 3, NULL, 5, NULL, NULL, NULL, 7};

    // right-skewed tree
    // int arr[] = {8,    NULL, 3,    NULL, NULL, NULL, 2, NULL,
    //              NULL, NULL, NULL, NULL, NULL, NULL, 1};

    // int arr[] = {8, 3, 5, 4, 9, 11, 21};
    int arr[] = {4, 2, 40, 42, 5, 35, 6, 25, 24};
#else
    // another example tree to test.
    auto twelve = new itreenode(12);
    auto eleven = new itreenode(11);
    auto ten = new itreenode(10, nullptr, eleven);
    auto nine = new itreenode(9, nullptr, ten);
    auto eight = new itreenode(8, nine, twelve);
    auto four = new itreenode(4, nullptr, eight);
    auto twenty = new itreenode(20);
    auto three = new itreenode(3, four, twenty);
    auto six = new itreenode(6);
    auto seven = new itreenode(7);
    auto two = new itreenode(2, six, seven);
    auto one = new itreenode(1, two, three);
    binary_tree<int> binaryTree(one);
 #endif

#if 0
    iBstNode *ten = new iBstNode(10);
    iBstNode *thirteen = new iBstNode(13);
    iBstNode *twelve = new iBstNode(12, ten, thirteen);

    iBstNode *one = new iBstNode(1);
    iBstNode *four = new iBstNode(4);
    iBstNode *three = new iBstNode(3, nullptr, four);
    iBstNode *two = new iBstNode(2, one, three);
    iBstNode *six = new iBstNode(6);
    iBstNode *eight = new iBstNode(8);
    iBstNode *seven = new iBstNode(7, six, eight);
    iBstNode *five = new iBstNode(5, two, seven);

    iBstNode *eight2 = new iBstNode(8, five, twelve);

    iBstNode *root = eight2;

    auto *t = deleteFromBSTIterative(root, 5);
#else
    iBst bst(arr, ARRAY_SIZE(arr));
    iBstNode *root = bst.getRoot();

    std::cout << "The min value in the BST is: " << bst.getMin() << std::endl;
    std::cout << "The max value in the BST is: " << bst.getMax() << std::endl;

    iBstNode *minNode = bst.getMinNode();
    iBstNode *maxNode = bst.getMaxNode();

#endif

    bst.remove(25);

    int x = 0;
}
