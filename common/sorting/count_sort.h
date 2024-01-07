#if !defined(count_sort_h)

#include <defines.h>

// NOTE: Here, we create an array with size matching the max number present in
// the given array + 1. then if we see a number in the original array, the
// corresponding index in the aux array gets incremented by 1. Basically, we
// count how much we saw a specific element in the given array. For example, if
// we see a 6 in the given array, the value of index 6 in the aux array gets
// incremented by 1. Then we go through the aux array and start filling the
// given array sorting it as a result.
void
countSort(int *arr, int size)
{
    int max = maxValueInArray(arr, size);
    if(max == -1) {
        std::cout << "Array has negative elements. cannot be sorted using "
                     "count sort.\n";
        return;
    }
    int auxSize = max + 1;
    int auxIndex = 0;
    int *aux = new int[auxSize];
    ZERO_ARRAY(aux, auxSize);

    for (int i = 0; i < size; ++i) {
        int n = arr[i];
        aux[n] += 1;
    }

    for (int i = 0, j = 0; i < auxSize; ++i) {
        int c = aux[i];
        while(c-- > 0) {
            arr[j++] = i;
        }
    }

    delete[] aux;
}

#define count_sort_h
#endif