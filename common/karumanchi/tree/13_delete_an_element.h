#if !defined(q013_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>

void
printPath(binary_tree_node<int> *root, int item)
{
    // post-order
    stack<binary_tree_node<int> *> s{32};
    std::vector<int> path;

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
        binary_tree_node<int> *prev;
        while(!s.isEmpty()) {
            // std::cout << curr->val << " <-- ";
            path.push_back(curr->val);
            if(curr->right && curr->right == s.peek()) {
                s.pop();
            }
            prev = curr;
            curr = s.pop();
            if(curr->right == prev) {
                path.push_back(1);
            } else {
                path.push_back(-1);
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

itreenode *
Q13(itreenode *root, itreenode **parent, int itemToFind, itreenode **foundItem)
{
    if(root== nullptr) {
        return nullptr;
    }

    queue<binary_tree_node<int> *> q{32, nullptr};
    stack<itreenode *> s{32};
    s.push(root);

    q.enqueue(root);

    binary_tree_node<int> *deepestNode = nullptr;

    while(!q.isEmpty())
    {
        deepestNode = q.dequeue();
        if(deepestNode->val == itemToFind) {
            *foundItem = deepestNode;
        }

        auto *left = deepestNode->left;
        auto *right = deepestNode->right;
        if(left)
        {
            q.enqueue(left);
        }
        if(right) {
            q.enqueue(right);
        }

        if(left || right) {
            if (!s.isEmpty() && s.peek() != deepestNode) {
                s.push(deepestNode);
            }
        }
    }

    if(!s.isEmpty()) {
        *parent = s.pop();
    }


    return deepestNode;
}

bool
deleteElement(binary_tree_node<int> *root, int item)
{
    bool result = false;

    itreenode *itemToDelete;
    itreenode *parent;
    itreenode *deepest = Q13(root, &parent, item, &itemToDelete);

    std::cout << "deepest node is " << deepest->val
              << ", and its parent is: " << parent->val << std::endl;
    std::cout << "item to delete has been found with value: "
              << itemToDelete->val << "\n";

    // NOTE: Basically, what you do here is you replace the val of the deleted
    // item with the deepst node value, and then free it.

    return result;
}


#define q013_h
#endif
