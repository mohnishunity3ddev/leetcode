#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <karumanchi/tree/q010.h>

using namespace std;


int
main()
{
    // int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, NULL, 301, 3123, NULL, 601, 701};
    int arr[] = {8, 3, 5, 4, 9, 7, 2};
    ibt binaryTree(arr, ARRAY_SIZE(arr));
    heightOfBinaryTree(binaryTree.getRoot());
}
