#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>

using namespace std;


int
main()
{
    // int arr[] = {5, 8, 6, NULL, 9, 3, 4, NULL, NULL, 4, 2};
    // int arr[] = {8, 3, 5, 4, 9, 7, 2};
    int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, NULL, 301, NULL, NULL, 601, 701};
    // int arr[] = {8};

    // left-skewed tree
    // int arr[] = {8, 3, NULL, 5, NULL, NULL, NULL, 7};

    // right-skewed tree
    // int arr[] = {8, NULL, 3, NULL, NULL, NULL, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 1};

    ibt binaryTree(arr, ARRAY_SIZE(arr));

    binaryTree.preorder();
    binaryTree.inorder();
    binaryTree.postorder();

}
