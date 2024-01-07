#if !defined(merge_sort_recursive_h)

#include <defines.h>
#include <iostream>

// Here, first subarray [l, ..., mid]
// second subarray [mid+1, ..., high]

// Basically in first array, l is the index of the first array element, mid is
// the index of last array element.
// in second array, mid+1 is the start of the second array element, high is the
// index of the last array element.
void
mergeResursiveVersion(int *arr, int low, int mid, int high)
{
    // Take a new auxilliary array where the merge result will be copied.
    int size = high - low + 1;
    int *aux = new int[size];
    int auxIndex = 0;
    int i = low, j = (mid + 1);

    while((auxIndex < size) && (i <= mid) && (j <= high)) {
        if (arr[i] < arr[j]) {
            aux[auxIndex++] = arr[i++];
        } else {
            aux[auxIndex++] = arr[j++];
        }
    }

    while(i <= mid) {
        aux[auxIndex++] = arr[i++];
    }
    while(j <= high) {
        aux[auxIndex++] = arr[j++];
    }

    // copy the sorted result back into the original array
    for (int i=low, j=0; ((j < size) && (i <= high)); ++i, ++j) {
        arr[i] = aux[j];
    }

    delete[] aux;
}


void
mergeSortRecursive(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = ((low + high) / 2);
        mergeSortRecursive(arr, low, mid);
        mergeSortRecursive(arr, mid + 1, high);
        // std::cout << "merging (" << low << ", " << mid << ", " << high
        //           << ").\n";
        mergeResursiveVersion(arr, low, mid, high);
    }
}

#define merge_sort_recursive_h
#endif