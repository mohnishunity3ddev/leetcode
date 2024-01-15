#if !defined (SORTED_SINGLE_LL_TO_HEIGHT_BALANCE_BST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
sortedListToBst(ll_node<int> **llNode, int start, int end)
{
    if(start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    iBstNode *leftChild = sortedListToBst(llNode, start, mid-1);

    iBstNode *parent = new iBstNode((*llNode)->value, leftChild, nullptr);

    (*llNode) = (*llNode)->next;
    parent->right = sortedListToBst(llNode, mid+1, end);

    return parent;
}

void
sortedListToBst_test()
{
    linked_list<int> list{};
    for (int i = 1; i <= 16; ++i)
    {
        list.add(i);
    }

    iBstNode *root = sortedListToBst(&list.head, 0, list.size - 1);
    iBst balancedBST{root};

    balancedBST.inorder();
}

#define SORTED_SINGLE_LL_TO_HEIGHT_BALANCE_BST_H
#endif // SORTED_SINGLE_LL_TO_HEIGHT_BALANCE_BST_H