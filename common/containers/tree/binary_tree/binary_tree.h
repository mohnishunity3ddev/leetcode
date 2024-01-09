#if !defined(binary_tree_h)

#include <defines.h>
#include <containers/queue/queue.h>
#include "../tree.h"

template <typename T>
struct binary_tree
{
    binary_tree() : root(nullptr) {}
    binary_tree(T *arr, T size) { construct(arr, size); }

    ~binary_tree() { std::cout << "Binary tree destructor called!\n"; }

  private:
    std::unique_ptr<tree_node<T>> root;

    void
    construct(T *arr, T size)
    {
        queue<tree_node<T> *> q = queue<tree_node<T> *>(size);
        
        root = std::make_unique<tree_node<T>>(arr[0], 0);
        q.enqueue(root.get());

        while(!q.isEmpty()) {
            tree_node<T> *parent = q.dequeue();
            int parentIndex = parent->arrIndex;
            int lci = (parentIndex * 2) + 1;
            if(lci < size && arr[lci] != NULL) {
                auto node = std::make_unique<tree_node<T>>(arr[lci], lci);
                q.enqueue(node.get());
                parent->left = std::move(node);
            }
            int rci = (parentIndex * 2) + 2;
            if(rci < size && arr[rci] != NULL) {
                auto node = std::make_unique<tree_node<T>>(arr[rci], rci);
                q.enqueue(node.get());
                parent->right = std::move(node);
            }
        }

        ASSERT(q.isEmpty());
    }
};

#define binary_tree_h
#endif