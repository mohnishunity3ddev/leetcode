#if !defined(RANGESUMBST_H)

#include "defines.h"
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode *temp = root;
        while(temp->left != nullptr)
        {
            temp = temp->left;
        }

        int sum = 0;
        while((temp->left != nullptr) && (temp->right != nullptr))
        {

        }
    }

    void driver() {
        TreeNode *node3 = new TreeNode(3);
        TreeNode *node7 = new TreeNode(7);
        TreeNode *node5 = new TreeNode(5, node3, node7);
        TreeNode *node18 = new TreeNode(18);
        TreeNode *node15 = new TreeNode(15, nullptr, node18);
        TreeNode *node10 = new TreeNode(10, node5, node15);

        int res = rangeSumBST(node10, 7, 15);
        printf("the range sum of this bst is: %d\n", res);
    }
};

#define RANGESUMBST_H
#endif // RANGESUMBST_H