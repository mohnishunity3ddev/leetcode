#if !defined(insert_sort_h)

#include <defines.h>

// 2, 3, 1, 5, 4
void
insertionSort(i32 *arr, i32 n)
{
    for (i32 i = 1; i < n; ++i)
    {
        int itemToSort = arr[i];
        int insertIndex = -1;
        int j = i - 1;
        while((j >= 0) && (itemToSort < arr[j]))
        {
            arr[j + 1] = arr[j];
            insertIndex = j;
            j--;
        }
        if(insertIndex != -1) {
            arr[insertIndex] = itemToSort;
        }
    }
}

#define insert_sort_h
#endif
