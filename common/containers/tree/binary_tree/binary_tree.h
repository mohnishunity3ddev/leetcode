#if !defined(binary_tree_h)

#include <defines.h>
#include <containers/queue/queue.h>
#include <containers/stack/stack.h>

template <typename T>
struct binary_tree_node
{
    T val;
    int arrIndex = -1;
    binary_tree_node<T> *left;
    binary_tree_node<T> *right;

    binary_tree_node() : val(0), arrIndex(0), left(nullptr), right(nullptr) {}
    binary_tree_node(T x) : val(x), left(nullptr), right(nullptr) {}
    binary_tree_node(T x, int arrIndex)
        : val(x), arrIndex(arrIndex), left(nullptr), right(nullptr)
    {
    }
    binary_tree_node(T x, binary_tree_node *left, binary_tree_node *right)
        : val(x), left(left), right(right)
    {
    }
    binary_tree_node(T x, int arrIndex, binary_tree_node *left,
                     binary_tree_node *right)
        : val(x), arrIndex(arrIndex), left(left), right(right)
    {
    }

    ~binary_tree_node()
    {
        std::cout << "tree_node desctructor called for value: " << val
                  << " and at index " << arrIndex << ".\n";
    }
};
typedef binary_tree_node<int> itreenode;

template <typename T>
struct binary_tree_traversal
{
    static void
    preorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            std::cout << root->val << ", ";
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    static void
    inorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            inorderRecursive(root->left);
            std::cout << root->val << ", ";
            inorderRecursive(root->right);
        }
    }

    static void
    postorderRecursive(binary_tree_node<T> *root)
    {
        if (root != nullptr)
        {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
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
                curr = curr->left;
            }
            if(!s.isEmpty())
            {
                curr = s.pop();
                curr = curr->right;
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
                curr = curr->left;
            }
            else
            {
                if (!s.isEmpty())
                {
                    curr = s.pop();
                    std::cout << curr->val << ", ";

                    curr = curr->right;
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
                auto *right = curr->right;
                if(right) {
                    s.push(right);
                }
                s.push(curr);

                curr = curr->left;
            }

            curr = s.pop();

            auto *right = curr->right;
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

    static void
    levelOrderTraversal(binary_tree_node<T> *root)
    {
        queue<binary_tree_node<T> *> q{32, nullptr};

        q.enqueue(root);

        while(!q.isEmpty())
        {
            auto *curr = q.dequeue();
            std::cout << curr->val << ", ";

            if(curr->left) {
                q.enqueue(curr->left);
            }
            if(curr->right) {
                q.enqueue(curr->right);
            }
        }
    }
};

template <typename T>
struct binary_tree
{
    binary_tree() : root(nullptr) {}
    binary_tree(T *arr, T size) { construct(arr, size); }
    binary_tree(binary_tree_node<T> *root) : root(root) {}

    ~binary_tree() {
        std::cout << "Binary tree destructor called!\n";
        clear();
    }

    binary_tree_node<T> *getRoot()
    {
        return root;
    }

    void preorder() {
        std::cout << "Pre-order traversal recursive: \n";
        binary_tree_traversal<T>::preorderRecursive(root);
        std::cout << "\n";
        std::cout << "Pre-order traversal iterative: \n";
        binary_tree_traversal<T>::preorderIterative(root);
        std::cout << "\n";
    }

    void inorder() {
        std::cout << "In-order traversal recursive: \n";
        binary_tree_traversal<T>::inorderRecursive(root);
        std::cout << "\n";
        std::cout << "In-order traversal iterative: \n";
        binary_tree_traversal<T>::inorderIterative(root);
        std::cout << "\n";
    }

    void postorder() {
        std::cout << "Post-order traversal recursive: \n";
        binary_tree_traversal<T>::postorderRecursive(root);
        std::cout << "\n";
        std::cout << "Post-order traversal iterative: \n";
        binary_tree_traversal<T>::postorderIterative(root);
        std::cout << "\n";
    }

    void levelOrder() {
        std::cout << "Level-order traversal: \n";
        binary_tree_traversal<T>::levelOrderTraversal(root);
        std::cout << "\n";
    }

    void
    printRootToItemPath(T item)
    {
        // post-order
        stack<binary_tree_node<T> *> s{32};
        std::vector<T> path;

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
            binary_tree_node<T> *prev;
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

    static void
    test()
    {
        // int arr[] = {5, 8, 6, NULL, 9, 3, 4, NULL, NULL, 4, 2};

        // complete binary-tree
        // int arr[] = {8, 3, 5, 4, 9, 7, 2};
        // complete binary-tree
        int arr[] = {8, 3, 5, 4, 9, 7, 2, 101, 0, 301, 0, 0, 601, 701};
        // int arr[] = {8};

        // left-skewed tree
        // int arr[] = {8, 3, NULL, 5, NULL, NULL, NULL, 7};

        // right-skewed tree
        // int arr[] = {8, NULL, 3, NULL, NULL, NULL, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 1};

        binary_tree<int> binaryTree(arr, ARRAY_SIZE(arr));

        binaryTree.preorder();
        binaryTree.inorder();
        binaryTree.postorder();
        binaryTree.levelOrder();
    }

  private:
    binary_tree_node<T> *root;

    void
    construct(T *arr, T size)
    {
        queue<binary_tree_node<T> *> q = queue<binary_tree_node<T> *>(size, nullptr);

        root = new binary_tree_node<T>(arr[0], 0);
        q.enqueue(root);

        while(!q.isEmpty()) {
            binary_tree_node<T> *parent = q.dequeue();
            int parentIndex = parent->arrIndex;
            int lci = (parentIndex * 2) + 1;
            if(lci < size && arr[lci] != NULL) {
                auto node = new binary_tree_node<T>(arr[lci], lci);
                q.enqueue(node);
                parent->left = node;
            }
            int rci = (parentIndex * 2) + 2;
            if(rci < size && arr[rci] != NULL) {
                auto node = new binary_tree_node<T>(arr[rci], rci);
                q.enqueue(node);
                parent->right = node;
            }
        }

        ASSERT(q.isEmpty());
    }

    void
    clear()
    {
        if(this->root == nullptr) {
            return;
        }

        // post order
        stack<binary_tree_node<T> *> s{32};
        auto *curr = this->root;

        do {
            while(curr != nullptr) {
                if(curr->right) {
                    s.push(curr->right);
                }
                s.push(curr);
                curr = curr->left;
            }

            curr = s.pop();

            if(curr->right && curr->right == s.peek()) {
                s.pop();
                s.push(curr);
                curr = curr->right;
            } else {
                delete curr;
                curr = nullptr;
            }
        } while (!s.isEmpty());
    }
};

typedef binary_tree<int> ibt;

#define binary_tree_h
#endif