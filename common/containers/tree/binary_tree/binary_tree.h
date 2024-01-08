#if !defined(binary_tree_h)

#include <defines.h>

struct binary_tree
{
    int val;
    binary_tree *left;
    binary_tree *right;

    binary_tree() : val(0), left(nullptr), right(nullptr) {}
    binary_tree(int x) : val(x), left(nullptr), right(nullptr) {}
    binary_tree(int x, binary_tree *left, binary_tree *right) : val(x), left(left), right(right) {}
    binary_tree(int *arr, int size) { construct(arr, size); }

    void
    construct(int *arr, int size)
    {
        for(int i = 0; i < size; ++i) {
            
        }
    }
};

#define binary_tree_h
#endif