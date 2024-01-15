#if !defined (SORTED_DLL_TO_HEIGHT_BALANCE_BST_H)

#include <containers/queue/queue.h>
#include <containers/stack/stack.h>
#include <containers/linked_list/double_linked_list.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <iostream>

iBstNode *
dllToBalancedBSt(iDll *dll, int start, int end)
{
    if(start > end) {
        return nullptr;
    }

    if(start == end) {
        int x = 0;
    }



    int mid = start + (end - start) / 2;
    iDllNode *dllNode = dll->getNode(mid);

    iBstNode *treeNode = new iBstNode(dllNode->value);
    treeNode->left = dllToBalancedBSt(dll, start, mid - 1);
    treeNode->right = dllToBalancedBSt(dll, mid+1, end);

    return treeNode;
}

#define SORTED_DLL_TO_HEIGHT_BALANCE_BST_H
#endif // SORTED_DLL_TO_HEIGHT_BALANCE_BST_H