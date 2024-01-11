#if !defined(q019_h)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <iostream>
#include <math.h>

// Find the level with maximum sum. Fill in elements in the tree level by level
// in the levelLElements vector passed in.
int
findMaxSumLevel(itreenode *root, std::vector<std::vector<int>> &levelElements)
{
    int result = 0;
    if(root == nullptr) {
        return 0;
    }

    int level = 1;
    int currentSum = 0, maxSum = 0, maxLevel = level;
    queue<itreenode *> q{32};

    q.enqueue(root);

    std::vector<int> l;
    levelElements.push_back(l);

    // marking the end of a level by inserting a nullpointer to the queue.
    q.enqueue(nullptr);

    while(!q.isEmpty()) {
        auto *curr = q.dequeue();

        if(curr != nullptr) {
            currentSum += curr->val;

            auto *left = curr->left.get();
            auto *right = curr->right.get();
            if(left) {
                q.enqueue(left);
            }
            if(right) {
                q.enqueue(right);
            }
        }
        else if(curr == nullptr) // denotes the end of a tree level.
        {
            // add a new vector for a new level.
            std::vector<int> l;
            levelElements.push_back(l);
            levelElements[level - 1].push_back(currentSum);

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = level;
            }
            currentSum = 0;

            // This is to make sure, the last element in the queue which does
            // not make the queue empty adds a new marker to signify the end of
            // a tree level.
            if(!q.isEmpty()) {
                q.enqueue(nullptr);
            }
            level++;
        }
    }

    std::cout << "The max sum is " << maxSum << " in level " << maxLevel
              << std::endl;

    return result;
}

#define q019_h
#endif
