#if !defined(binary_search_tree_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <defines.h>


template <typename T>
struct binary_search_tree_node
{
    T val;
    int arrIndex = -1;
    binary_search_tree_node<T> *left;
    binary_search_tree_node<T> *right;

    binary_search_tree_node()
        : val(0), arrIndex(0), left(nullptr), right(nullptr)
    {
    }
    binary_search_tree_node(T x) : val(x), left(nullptr), right(nullptr) {}
    binary_search_tree_node(T x, int arrIndex)
        : val(x), arrIndex(arrIndex), left(nullptr), right(nullptr)
    {
    }
    binary_search_tree_node(T x, binary_search_tree_node *left,
                            binary_search_tree_node *right)
        : val(x), left(left), right(right)
    {
    }
    binary_search_tree_node(T x, int arrIndex, binary_search_tree_node *left,
                            binary_search_tree_node *right)
        : val(x), arrIndex(arrIndex), left(left), right(right)
    {
    }

    ~binary_search_tree_node()
    {
        std::cout << "BST Node desctructor called for value: " << val
                  << " and at index " << arrIndex << ".\n";
    }
};
#define bstNode binary_search_tree_node
#define bst binary_search_tree
typedef binary_search_tree_node<int> iBstNode;

template <typename T>
struct binary_search_tree
{
    binary_search_tree() : root(nullptr) {}
    binary_search_tree(bstNode<T> *root) : root(root) {}
    binary_search_tree(T *arr, int size) { construct(arr, size); }

    ~binary_search_tree()
    {
        std::cout << "BST destructor called!\n";
        clear();
    }

    bstNode<T> *
    getRoot()
    {
        return root;
    }

    T getMin() {
        bstNode<T> *curr = this->root;

        while(curr->left != nullptr) {
            curr = curr->left;
        }

        return curr->val;
    }

    bstNode<T> *
    getMinNode()
    {
        bstNode<T> *curr = this->root;
        while(curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    T
    getMax()
    {
        bstNode<T> *curr = this->root;
        while(curr->right != nullptr) {
            curr = curr->right;
        }
        return curr->val;
    }

    bstNode<T> *
    getMaxNode()
    {
        bstNode<T> *curr = this->root;
        while(curr->right != nullptr) {
            curr = curr->right;
        }
        return curr;
    }


    void
    insert(T data)
    {
        if(this->root == nullptr) {
            this->root = new bstNode<T>(data);
            return;
        }

        bstNode<T> *newNode = new bstNode<T>(data);
        auto *curr = this->root;
        while(curr != nullptr) {
            if(data < curr->val) {
                if(curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = newNode;
                    break;
                }
            } else if(data > curr->val) {
                if(curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = newNode;
                    break;
                }
            } else {
                break;
            }
        }
    }

    // NOTE: When removing nodes from a BST, we have to do the following:
    // 1.   Find the node to delete, if its not there, return null.
    // 2.   Check how many children the node to be deleted has,
    // 2a.  if it has no children, set its parent right/left pointer to null, and free it.
    // 2b.  if it has one child, set its parent left/right to deleted node's
    //      left/right so that its child is now a direct child to its parent.
    // 2c.  if it has two children, get the max node in its left subtree, that
    //      node will only have a left child, the node that we found, set the
    //      found node's value to be this. and delete that max node. Check if it
    //      has one child, if it does, set its child directly to be the child of
    //      its parent and free the max node.
    void
    remove(T data)
    {
        if(this->root == nullptr) {
            std::cout << "Nothing to delete\n";
            return;
        }

        // find the node to delete.
        auto *curr = this->root;
        bstNode<T> *parent = nullptr;
        while(curr != nullptr && curr->val != data) {
            parent = curr;
            if(data < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if(curr == nullptr || curr->val != data) {
            // NOTE: We were not able to find the node.
            return;
        }

        auto *temp = curr;
        // NOTE: Now, curr points to the node that we want to delete.
        // We first check the number of children that it has.
        if(!curr->left && !curr->right) {
            // it has no children.
            if(curr->val > parent->val) {
                parent->right = nullptr;
            } else {
                parent->left = nullptr;
            }
            delete temp;
            curr = nullptr;
        } else if(curr->left != nullptr && curr->right != nullptr) {
            // it has two children.

            // Here, we replace the "node to be deleted"'s val to be the val
            // held by the max value node in its left subtree and then
            // free/delete THAT max node in its left subtree. The max node in
            // any BST only has a left child atmost, may have no children at
            // all. In either case, it is easy to delete it.
            auto *pD = curr;

            // Move to the "node to be deleted"'s left subtree.
            parent = pD;
            curr = curr->left;
            // move to the right-most (max) node in its left subtree.
            while(curr->right != nullptr) {
                parent = curr;
                curr = curr->right;
            }
            // set the "to be deleted node"'s value to be that of the value of
            // the max node of its left subtree and then free it.
            pD->val = curr->val;
            // Check if the max node has a left child. If it has then set its
            // parent's right to be its left.
            temp = curr;
            // bypass the node and then free it.
            parent->right = curr->left;
            delete temp;
            curr = nullptr;
        } else {
            // It has only one child.
            // now we have to figure whether this deleted node is the left/right
            // child of its parent.
            bool isLeftChild = (curr->val < parent->val);

            // the deleted node has a left child.
            if(curr->left) {
                // this bypasses the curr node and set its child directly to be
                // the child of its parent.
                if(curr->val < parent->val) {
                    parent->left = curr->left;
                } else {
                    parent->right = curr->left;
                }
            } else if(curr->right) {
                if(curr->val < parent->val) {
                    parent->left = curr->right;
                } else {
                    parent->right = curr->right;
                }
            }
            delete curr;
            curr = nullptr;
        }


    }

  private:
    bstNode<T> *root = nullptr;

    void
    construct(T *arr, int size)
    {
        insert(arr[0]);
        for(int i = 1; i < size; ++i) {
            insert(arr[i]);
        }
    }

    void
    clear()
    {
        if (this->root == nullptr) {
            return;
        }

        // post order
        stack<bstNode<T> *> s{32};
        auto *curr = this->root;

        do
        {
            while (curr != nullptr) {
                if (curr->right) {
                    s.push(curr->right);
                }
                s.push(curr);
                curr = curr->left;
            }

            curr = s.pop();

            if (curr->right && curr->right == s.peek()) {
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

typedef binary_search_tree<int> iBst;

#define binary_search_tree_h
#endif