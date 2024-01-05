#if !defined(selection_sort_h)

#include <defines.h>

// -> Here, we select the position first, and then find the minimum element
// which should be placed in that selected position.
// -> For n items, this algorithm needs to do n-1 passes. After k passes, k
// minimum elements are placed and are sorted. So, if we want to sort k elements
// or if we want the least k digits in the array, selection sort is the way to
// go.
// -> if the list is already sorted, even then it takes O(n^2) time, like
// insertion and bubble sort, this is not adaptive.
void
selectionSort(i32 *arr, i32 size)
{
    for(i32 i = 0; i < (size-1); ++i)
    {
        i32 selectedIndex = i;
        i32 minimumIndex = selectedIndex;
        for(i32 j = (selectedIndex + 1); j < size; ++j)
        {
            if(arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }
        if(selectedIndex != minimumIndex) {
            swap(arr[selectedIndex], arr[minimumIndex]);
        }
    }
}

#define selection_sort_h
#endif