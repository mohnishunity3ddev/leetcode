#if !defined(shell_sort_h)

#include <defines.h>
#include <iostream>

// NOTE:
// shellSort works like insertion sort but on subset of arrays in subsequent
// passes. insertion sort works like this: for each element, it checks preceding
// elements to see if they are larger, if they are, then the current element
// gets inserted to the left and the elements keep shifitng right as they are
// larger. One nice property of insertion sort is that if the given array is
// already sorted, then it takes O(n) time to go through them before returning.
// shell sort uses this property of insertion sort, where at the beginning it
// only applies insertion sort logic to every "gap" elements each pass. After
// the pass is completed, it divides the gap by 2 and then again applies insert
// logic on every [gap/2] element, last pass the "gap" is 1, so it is exactly
// like insertion sort, only this time the no of shifts left will be very low
// since the list will be largely sorted already.
// NOTE: Basically, the best time of insertion sort is O(n) and shell sort
// creates an environment for insertion sort in its last pass(where "gap" is 1
// so shell sort is exactly like insertion sort here) in a way where the
// insertion sort gets an array which is somewhat sorted and so insertion sort
// gets its best case scenario where the running time is O(n).
// NOTE: Since number of passes is logn(gap gets divided by 2 each pass).
// Running time of shell sort is O(nlogn). It is used for very large arrays. AND
// it is in-place so it does not need any additional memory.
void
shellSort(int *arr, int size)
{
    int gap = (size/2);

    while(gap >= 1)
    {
        for(int i = (gap); i < size; ++i)
        {
            int j = i;
            while((j - gap) >= 0)
            {
                if(arr[j] < arr[j-gap])
                {
                    swap(arr[j], arr[j - gap]);
                }
                j -= gap;
            }
        }

        gap /= 2;
    }
}

#define shell_sort_h
#endif