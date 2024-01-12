#if !defined(q029_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

itreenode *
q28_getNode(itreenode *root, int item)
{
    if(root == nullptr) {
        return nullptr;
    }

    if(root->val == item) {
        return root;
    }

    itreenode *node = q28_getNode(root->left, item);
    if(node == nullptr) {
        node = q28_getNode(root->right, item);
    }

    return node;
}

// We are using post-order traversal here since all ancestors of the node are
// there in the stack when we find the provided node in the tree.
// the only problem is, the right children of the ancestors are also there along
// with the parents. so, we need to remove them to get the actual ancestors of a
// node.
void
printAllAncestorsIterative(itreenode *root, itreenode *node)
{
    stack<itreenode *> s{32};
    itreenode *curr = root;
    bool nodeFound = false;

    do
    {
        while(curr != nullptr) {
            if(curr->right) {
                s.push(curr->right);
            }
            s.push(curr);
            curr = curr->left;
        }

        curr = s.pop();

        if(curr->right && s.peek() == curr->right) {
            s.pop();
            s.push(curr);
            curr = curr->right;
        } else {
            if(curr == node) {
                nodeFound = true;
            } else {
                // std::cout << curr->val << ", ";
                curr = nullptr;
            }
        }

    } while (!nodeFound && !s.isEmpty());

    if(nodeFound) {
        while(!s.isEmpty()) {
            // we have to check whether the popped element is the right child of
            // the found node's parent. as you can see above, we first push any
            // node's right child node first before pushing the actual node. so
            // the potential parent is at the top of its right child.
            itreenode *parent = s.pop();
            std::cout << parent->val << ", ";
            itreenode *peek = s.peek();
            if(peek != nullptr) {
                if (parent->right == peek && peek->left != curr &&
                    peek->right != curr)
                {
                    s.pop();
                }
            } else {
                break;
            }
            curr = parent;
        }
    } else {
        std::cout << "Could not find node with value: " << node->val
                  << " in the given tree.\n";
        return;
    }
}

bool
printAllAncestorsRecursive(itreenode *root, itreenode *node) {
    if(root == nullptr) {
        return false;
    }

    if (root->left == node || root->right == node ||
        printAllAncestorsRecursive(root->left, node) ||
        printAllAncestorsRecursive(root->right, node))
    {
        std::cout << root->val << ", ";
        return true;
    }

    return false;
}

void
printAllAncestors(itreenode *root, itreenode *node)
{
    printAllAncestorsIterative(root, node);
}

void
printAllAncestors(itreenode *root, int item)
{
    auto *node = q28_getNode(root, item);
    printAllAncestors(root, node);
}

#define q029_h
#endif
