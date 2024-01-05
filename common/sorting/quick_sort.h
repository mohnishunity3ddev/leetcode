#if !defined(quick_sort_h)

#include <defines.h>

// NOTE: This routine partitions the array into two, where the partitioned array
// to left is smaller than the pivot element, and the one to the right are
// elements greater than the pivot element.
int
partition(int *arr, int low, int high)
{
    // selecting the middle element as the pivot // 944672
    int pivot = arr[low];
    int i = low, j = high;

    do
    {
        // keep going right of the array until we get an element which is greater than the pivot.
        do { i++; } while (arr[i] <= pivot && i < high);
        // keep going left of the array until we get an element which is smaller than the pivot.
        do { j--; } while (arr[j] > pivot && j >= low);

        if(i < j) {
            swap(arr[i], arr[j]);
        }
    } while(i < j);

    // NOTE: when i < j, there is no need checking the array, because i goes
    // right checking for large elements, and j goes left checking for smaller
    // elements than pivot, there is no need advancing them now since j that was
    // checking for smaller elements has already crossed i, which means all
    // elements to the right of i are already greater than the pivot, so by
    // advancing i(which was checking for smaller elements than pivot) will
    // always fail, so we stop when i < j.

    // NOTE: Why do we select j to be index where we place the pivot element?
    // j points to an element which is smaller than the pivot, since it should
    // be to the left of the pivot element, and we have checked the entire
    // array(since i < j) - we do one last swap to get the pivot element to the
    // proper position in the array so that elements to the left are smaller and
    // elements to the right are greater.

    // NOTE: what if we select i to be the one which we use to swap the pivot
    // element to. i stops at a value when the ith element is greater than
    // pivot. if we swap using the ith element, the pivot will come after the
    // larger element, meaning the larger element will come to the left of pivot
    // which will be wrong.

    swap(arr[low], arr[j]);
    return j;
}

void
quicksort(i32 *arr, i32 low, i32 high)
{
    if(high <= low) return;

    i32 p = partition(arr, low, high);
    quicksort(arr, low, p);
    quicksort(arr, p + 1, high);
}

#define quick_sort_h
#endif