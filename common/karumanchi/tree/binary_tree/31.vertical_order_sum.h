#if !defined(q031_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <math.h>

#include <iostream>
#include <map>

// NOTE: The root is at column 0. if we go left, we decrement the column by 1. if we go right, we increment the column by 1.
// Thhe root is also at level 0. if we go down, we increment the level by 1.
// the vertical is the column here we are talking about.
struct vertical_order{
    itreenode *node;
    int column;
    int level;
};

vertical_order invalidVO{nullptr, -1, -1};

void
verticalOrder(itreenode *root)
{
    queue<vertical_order> q{32, invalidVO};
    std::map<int, std::vector<int>> map;

    int column = 0, level = 0;
    vertical_order voRoot = {root, column, level};
    q.enqueue(voRoot);

    while(!q.isEmpty()) {
        vertical_order currVO = q.dequeue();
        auto *node = currVO.node;
        // std::cout << node->val << "(" << currVO.column << ", " << currVO.level << "), \n";
        map[currVO.column].push_back(node->val);

        vertical_order vo = {};

        if(node->left) {
            vo = {node->left, currVO.column - 1, currVO.level + 1};
            q.enqueue(vo);
        }
        if(node->right) {
            vo = {node->right, currVO.column + 1, currVO.level + 1};
            q.enqueue(vo);
        }
    }

    for(const auto &kvPair : map) {
        std::cout << "[column " << kvPair.first << "]: {";
        std::vector<int> v = kvPair.second;
        std::sort(v.begin(), v.end());
        int sum = 0;
        for(int node : v) {
            sum += node;
            std::cout << node << ", ";
        }
        std::cout << "}.    (Vertical Sum): " << sum << "\n";
    }
}

#define q031_h
#endif
