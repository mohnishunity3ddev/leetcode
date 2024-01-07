#if !defined(radix_sort_h)

#include <defines.h>
#include <containers/linked_list/linked_list.h>

// NOTE:
// Here, we do create bins like bucket sort, but we only create 10 bins for
// sorting positive decimal integers. SImilarly, for octal numbers, 8 bins are
// enough and for binary numbers two bins are enough. In radix sort, we do
// multiple passes each time sorting on the basis of a unit digit of the number
// at first. The unit digit will tell which "bin" or "bucket" of linked list the
// number will fall in. Next pass, we will now see the tens digit place and
// start placing the number in the bins. If the maximum value was 3 digits,
// radix sort will sort the numbers in 3 passes with O(dn) time, where d is the
// max number of digits of the max number and n is the number of elements in the
// given array.

// NOTE: Assuming decimal integers.
void
radixSort(int *arr, int size)
{
    int max = maxValueInArray(arr, size);
    if(max == -1)
    {
        std::cout << "There are negative number(s) in the array. Radix sort "
                     "only sorts arrays with all positive items.\n";
    }

    linked_list<int> *aux = new linked_list<i32>[10];

    int nPassesRequired = 0;
    int denom = 1;
    while(max != 0)
    {
        max /= 10;
        ++nPassesRequired;
    }

    for(int passIndex = 0;
        passIndex < nPassesRequired;
        ++passIndex, denom *= 10)
    {
        // NOTE: Looking at the digit at the unit's, ten's or hundreth's space
        // dpeending on the passIndex. And then inserting the array item to
        // "digit" index in the bucket list.
        for (int i = 0; i < size; ++i)
        {
            int n = arr[i];
            int digit = (n / denom) % 10;

            linked_list<int> *bucket = aux + digit;
            bucket->add(n);
        }

        // NOTE: Extracting the buckets out of the bucket list and inserting
        // them back to the original array.
        for (int i = 0, j = 0; i < 10; ++i)
        {
            linked_list<int> *bucket = aux + i;
            while(bucket->head != nullptr)
            {
                arr[j++] = bucket->head->value;
                bucket->removeAt(0);
            }
        }
    }

    delete[] aux;
}

#define radix_sort_h
#endif