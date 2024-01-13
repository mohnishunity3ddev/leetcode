#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <containers/linked_list/double_linked_list.h>

using namespace std;

struct test{

  private:
    int x;
    int y;

  public:
    static const int i = 10;
    test(int x, int y) : x(x) , y(y) {}
    int z;
};

void
printRootToItemPath(binary_tree_node<int> *root, int item)
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

int
main()
{
    double_linked_list<int> dll{};

    for (int i = 0; i < 10; ++i) {
        dll.add(i);
    }
    dll.addAt(4, 510);
    dll.display();
    dll.removeAt(4);
    dll.display();
    dll.displayReverse();

    int x = 0;
}
