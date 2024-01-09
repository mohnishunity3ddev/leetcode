#if !defined(binary_tree_h)

#include <defines.h>
#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include "../tree.h"

template <typename T>
struct binary_tree_node
{
    T val;
    int arrIndex;
    std::unique_ptr<binary_tree_node<T>> left;
    std::unique_ptr<binary_tree_node<T>> right;

    binary_tree_node() : val(0), arrIndex(0), left(nullptr), right(nullptr) {}
    binary_tree_node(T x) : val(x), left(nullptr), right(nullptr) {}
    binary_tree_node(T x, int arrIndex)
        : val(x), arrIndex(arrIndex), left(nullptr), right(nullptr)
    {
    }
    binary_tree_node(T x, std::unique_ptr<binary_tree_node> left,
              std::unique_ptr<binary_tree_node> right)
        : val(x), left(std::move(left)), right(std::move(right))
    {
    }
    binary_tree_node(T x, int arrIndex, std::unique_ptr<binary_tree_node> left,
              std::unique_ptr<binary_tree_node> right)
        : val(x), arrIndex(arrIndex), left(std::move(left)),
          right(std::move(right))
    {
    }

    ~binary_tree_node()
    {
        std::cout << "tree_node desctructor called for value: " << val
                  << " and at index " << arrIndex << ".\n";
    }
};

template <typename T>
struct binary_tree_traversal
{
    static void
    preorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            std::cout << root->val << ", ";
            preorderRecursive(root->left.get());
            preorderRecursive(root->right.get());
        }
    }

    static void
    inorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            inorderRecursive(root->left.get());
            std::cout << root->val << ", ";
            inorderRecursive(root->right.get());
        }
    }

    static void
    postorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            postorderRecursive(root->left.get());
            postorderRecursive(root->right.get());
            std::cout << root->val << ", ";
        }
    }

    static void
    preorderIterative(binary_tree_node<T> *root)
    {
        if(root == nullptr)
        {
            std::cout << "Traversal: root cannot be null!\n";
            return;
        }

        stack<binary_tree_node<T> *> s{32};
        binary_tree_node<T> *curr = root;

        bool done = false;

        while (!done)
        {
            while(curr != nullptr)
            {
                std::cout << curr->val << ", ";
                s.push(curr);
                curr = curr->left.get();
            }
            if(!s.isEmpty())
            {
                curr = s.pop();
                curr = curr->right.get();
            }
            else
            {
                done = true;
            }
        }
    }

    static void
    inorderIterative(binary_tree_node<T> *root)
    {
        if(root == nullptr)
        {
            std::cout << "Traversal: root cannot be null!\n";
            return;
        }

        stack<binary_tree_node<T> *> s{32};
        binary_tree_node<T> *curr = root;

        bool done = false;

        while (!done)
        {
            if (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left.get();
            }
            else
            {
                if (!s.isEmpty())
                {
                    curr = s.pop();
                    std::cout << curr->val << ", ";

                    curr = curr->right.get();
                }
                else
                {
                    done = true;
                }
            }
        }
    }

    static void
    postorderIterative(binary_tree_node<T> *root)
    {
        if(root == nullptr)
        {
            std::cout << "Traversal: root cannot be null!\n";
            return;
        }

        stack<binary_tree_node<T> *> s{32};
        binary_tree_node<T> *curr = root;

        do
        {
            while(curr != nullptr) {
                auto *right = curr->right.get();
                if(right) {
                    s.push(right);
                }
                s.push(curr);

                curr = curr->left.get();
            }

            curr = s.pop();

            auto *right = curr->right.get();
            if((right != nullptr) && (s.peek() == right)) {
                s.pop();
                s.push(curr);
                curr = right;
            }
            else {
                std::cout << curr->val << ", ";
                curr = nullptr;
            }

        } while (!s.isEmpty());
    }
};

template <typename T>
struct binary_tree
{
    binary_tree() : root(nullptr) {}
    binary_tree(T *arr, T size) { construct(arr, size); }

    ~binary_tree() { std::cout << "Binary tree destructor called!\n"; }

    binary_tree_node<T> *getRoot()
    {
        return root.get();
    }

    void preorder() {
        std::cout << "Pre-order traversal recursive: \n";
        binary_tree_traversal<T>::preorderRecursive(root.get());
        std::cout << "\n";
        std::cout << "Pre-order traversal iterative: \n";
        binary_tree_traversal<T>::preorderIterative(root.get());
        std::cout << "\n";
    }

    void inorder() {
        std::cout << "In-order traversal recursive: \n";
        binary_tree_traversal<T>::inorderRecursive(root.get());
        std::cout << "\n";
        std::cout << "In-order traversal iterative: \n";
        binary_tree_traversal<T>::inorderIterative(root.get());
        std::cout << "\n";
    }

    void postorder() {
        std::cout << "Post-order traversal recursive: \n";
        binary_tree_traversal<T>::postorderRecursive(root.get());
        std::cout << "\n";
        std::cout << "Post-order traversal iterative: \n";
        binary_tree_traversal<T>::postorderIterative(root.get());
        std::cout << "\n";
    }

    static void
    test()
    {
        int arr[] = {5, 8, 6, NULL, 9, 3, 4, NULL, NULL, 4, 2};

        // complete binary-tree
        // int arr[] = {8, 3, 5, 4, 9, 7, 2};
        // complete binary-tree
        // int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, NULL, 301, NULL, NULL, 601, 701};
        // int arr[] = {8};

        // left-skewed tree
        // int arr[] = {8, 3, NULL, 5, NULL, NULL, NULL, 7};

        // right-skewed tree
        // int arr[] = {8, NULL, 3, NULL, NULL, NULL, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 1};

        binary_tree<int> binaryTree(arr, ARRAY_SIZE(arr));

        binaryTree.preorder();
        binaryTree.inorder();
        binaryTree.postorder();
    }

  private:
    std::unique_ptr<binary_tree_node<T>> root;

    void
    construct(T *arr, T size)
    {
        queue<binary_tree_node<T> *> q = queue<binary_tree_node<T> *>(size);

        root = std::make_unique<binary_tree_node<T>>(arr[0], 0);
        q.enqueue(root.get());

        while(!q.isEmpty()) {
            binary_tree_node<T> *parent = q.dequeue();
            int parentIndex = parent->arrIndex;
            int lci = (parentIndex * 2) + 1;
            if(lci < size && arr[lci] != NULL) {
                auto node = std::make_unique<binary_tree_node<T>>(arr[lci], lci);
                q.enqueue(node.get());
                parent->left = std::move(node);
            }
            int rci = (parentIndex * 2) + 2;
            if(rci < size && arr[rci] != NULL) {
                auto node = std::make_unique<binary_tree_node<T>>(arr[rci], rci);
                q.enqueue(node.get());
                parent->right = std::move(node);
            }
        }

        ASSERT(q.isEmpty());
    }
};

typedef binary_tree<int> ibt;

#define binary_tree_h
#endif