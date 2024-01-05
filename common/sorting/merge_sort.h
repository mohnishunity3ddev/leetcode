#if !defined(merge_sort_h)

#include <defines.h>

// NOTE: Merges two separately sorted lists into the same array such that the
// merged array is again sorted. low is start of array, high is the end of the
// array, mid is the mid point of array where the first list ends, mid+1 is
// where the second list starts.
//
// NOTE: mid is where the first sorted subarray ends(inclusive).
// low is where the first sorted sublist starts.
// high is one past where the second sorted sublist ends.
void
merge(int *arr, int low, int mid, int high)
{
    // Take a new auxilliary array where the merge result will be copied.
    int size = high - low;
    int *aux = new int[size];
    int auxIndex = 0;
    int i = low, j = (mid + 1);

    while((auxIndex < size) && (i <= mid) && (j < high)) {
        if (arr[i] < arr[j]) {
            aux[auxIndex++] = arr[i++];
        } else {
            aux[auxIndex++] = arr[j++];
        }
    }

    while(i <= mid) {
        aux[auxIndex++] = arr[i++];
    }
    while(j < high) {
        aux[auxIndex++] = arr[j++];
    }

    // copy the sorted result back into the original array
    for (int i=low, j=0; ((j < size) && (i < high)); ++i, ++j) {
        arr[i] = aux[j];
    }

    delete[] aux;
}

// NOTE: the idea behind merge sort is that array of 8 ints can be thought of as
// an array with 8 lists with each list containing one element. A list with one
// element is already sorted. Then we merge two sorted lists into a sorted
// array. First, we start with 2 elements, then merge them to get array of 2,
// Select a pair merge them to get 4 element arrays, then merge them to get 8
// element arrays and so on, At the end, we will get a sorted array.
void
mergeSort(int *arr, int size)
{
    int currentSize;
    // NOTE: the i here, tells us how many number element arrays we have to
    // merge. In the first pass, we merge 1 element arrays to get 2. next,
    // we merge 2 element arrays to get 4, the next, we merge 4 element
    // arrays to get 8.
    //
    // NOTE: The reason why we have set the max limit of i to be that of the
    // original array size divided by 2 is because i denotes the length of the
    // array we have to merge. Two arrays with length size/2 when merge, give an
    // array of the original size.
    for(currentSize = 1; currentSize < size; currentSize *= 2)
    {
        // NOTE: in the first pass, we merge 1 element arrays to get 2 element
        // arrays second pass, we merge 2 element arrays to get 4 element arrays
        // the result of passIndex 0 is 2 element array pairs. and we merge 1
        // element arrays
        //
        // how many i-length array pairs are there that we have to merge in this
        // pass?
        //
        // NOTE:
        // low is where the first sorted sublist starts.
        // mid is where the first sorted subarray ends(inclusive).
        // high is one past where the second sorted sublist ends.
        for(i32 low = 0; low < size - 1; low += (2*currentSize))
        {
            // NOTE: it can happen that the subarray is not a perfect power
            // of 2. in that case we need to clamp the value of high and mid.
            i32 high = MIN(low + (2*currentSize), size);
            i32 mid = MIN(low + (currentSize-1), size);
            merge(arr, low, mid, high);
        }
    }
}

void
mergeSortRecursive(int *arr, int size)
{

}


#define merge_sort_h
#endif