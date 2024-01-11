#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <karumanchi/tree/q020.h>

using namespace std;


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

    int arr[] = {8, 3, 5, 4, 9, 7, 2};
    ibt binaryTree(arr, ARRAY_SIZE(arr));
#else
    // another example tree to test.

    auto twelve = std::make_unique<itreenode>(12);
    auto eleven = std::make_unique<itreenode>(11);
    auto ten = std::make_unique<itreenode>(10, nullptr, std::move(eleven));
    auto nine = std::make_unique<itreenode>(9, nullptr, std::move(ten));
    auto eight = std::make_unique<itreenode>(8, std::move(nine), std::move(twelve));
    auto four = std::make_unique<itreenode>(4, nullptr, std::move(eight));
    auto five = std::make_unique<itreenode>(5);
    auto three = std::make_unique<itreenode>(3, std::move(four), std::move(five));
    auto six = std::make_unique<itreenode>(6);
    auto seven = std::make_unique<itreenode>(7);
    auto two = std::make_unique<itreenode>(2, std::move(six), std::move(seven));
    auto one = std::make_unique<itreenode>(1, std::move(two), std::move(three));
    binary_tree<int> binaryTree(std::move(one));

 #endif

    int path[256];
    printRootToLeafPaths(binaryTree.getRoot(), path, 0);
}
