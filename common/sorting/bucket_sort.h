#if !defined(bucket_sort_h)

#include <defines.h>
#include <containers/linked_list/linked_list.h>

// NOTE
// Similar to count sort, here also, we make an aux array with max value of
// given array as number of elements. Here, the aux array is an array of linked
// lists. whenever we see a value in the given array instead of incrementing a
// counter value, we insert a new node into the corresponding linked list, the
// node has the same value that it saw in the original array.
void
bucketSort(int *arr, int size)
{
    int maxValue = maxValueInArray(arr, size);
    if(maxValue == -1)
    {
        std::cout << "There are negative integers in the array. Bucket sort "
                     "can't be used here!\n";
        return;
    }

    int auxSize = maxValue + 1;
    linked_list<int> *aux = new linked_list<i32>[auxSize];

    for (int i = 0; i < size; ++i)
    {
        int n = arr[i];

        auto *bucket = aux + n;
        bucket->add(n);
    }

    for (int i = 0, auxIndex = 0; auxIndex < auxSize; ++auxIndex)
    {
        auto *bucket = aux + auxIndex;
        while(bucket->head != nullptr)
        {
            arr[i++] = bucket->head->value;
            bucket->removeAt(0);
        }
    }

    delete[] aux;
}

void
binSort(int *arr, int size)
{
    bucketSort(arr, size);
}

#define bucket_sort_h
#endif