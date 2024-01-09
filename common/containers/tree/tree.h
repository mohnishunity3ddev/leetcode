#if !defined(tree_h)

#include <iostream>
#include <memory>

template <typename T>
struct tree_node
{
    T val;
    int arrIndex;
    std::unique_ptr<tree_node<T>> left;
    std::unique_ptr<tree_node<T>> right;

    tree_node() : val(0), arrIndex(0), left(nullptr), right(nullptr) {}
    tree_node(T x) : val(x), left(nullptr), right(nullptr) {}
    tree_node(T x, int arrIndex)
        : val(x), arrIndex(arrIndex), left(nullptr), right(nullptr)
    {
    }
    tree_node(T x, std::unique_ptr<tree_node> left,
              std::unique_ptr<tree_node> right)
        : val(x), left(std::move(left)), right(std::move(right))
    {
    }
    tree_node(T x, int arrIndex, std::unique_ptr<tree_node> left,
              std::unique_ptr<tree_node> right)
        : val(x), arrIndex(arrIndex), left(std::move(left)),
          right(std::move(right))
    {
    }

    ~tree_node()
    {
        std::cout << "tree_node desctructor called for value: " << val
                  << " and at index " << arrIndex << ".\n";
    }
};

#define tree_h
#endif