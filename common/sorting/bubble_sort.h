#if !defined(bubble_sort_h)

#include <defines.h>


void bubbleSort(i32 *arr, i32 n)
{
    for(i32 i = 0; i < n-1; ++i)
    {
        // NOTE: This oee here is a pass. In this pass, it is guaranteed that
        // the largest number will be sorted. meaning at the end of this pass,
        // the largest number will be at the end of the array.

        i32 flag = 0;

        // NOTE: Here, we see that we only let j go through the part of the
        // array that is not sorted, since in one pass, the largest number is
        // guaranteed to be at the end, we dont need to check it with the
        // previous element since it is already greater than that. so we negate
        // the number of passes that we have already gone through till now.
        for(i32 j = 0; j < n-1-i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }

        // NOTE: if in this pass, no swapping took place, that means the array
        // is already sorted, we dont need to go any further from here.
        if(!flag) {
            break;
        }
    }
}

#define bubble_sort_h
#endif