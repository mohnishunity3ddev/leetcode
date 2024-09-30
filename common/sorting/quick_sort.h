#if !defined(quick_sort_h)

#include <defines.h>
#include <containers/stack/stack.h>

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

struct interval {
    i32 low;
    i32 high;

    bool
    operator==(const interval &b)
    {
        return low == b.low && high == b.high;
    }
};

void
iterativeQuicksort(i32 *arr, i32 low, i32 high)
{
    if(high <= low) return;

    interval range{low, high};
    interval invalidInterval{-1, -1};
    stack<interval> _stack{32, invalidInterval};
    _stack.push(range);

    while(!_stack.isEmpty()) {
        interval currentRange = _stack.pop();
        if(currentRange == invalidInterval) {
            std::cout << "Received invalid interval! please check!\n";
            break;
        }

        i32 partitionIndex = partition(arr, currentRange.low, currentRange.high);

        if(partitionIndex > currentRange.low) {
            _stack.push({currentRange.low, partitionIndex});
        }
        if(partitionIndex + 1 < currentRange.high) {
            _stack.push({partitionIndex + 1, currentRange.high});
        }
    }
}

#define VERIFY_SORTED_ARRAY(arr, size)                                         \
    {                                                                          \
        for (int i = 1; i < size; ++i)                                         \
        {                                                                      \
            if (arr[i] < arr[i - 1])                                           \
            {                                                                  \
                ASSERT(!"Array is not sorted");                                \
            }                                                                  \
        }                                                                      \
    }

void
quicksort_test()
{
    int numTests = 1000;
    for (int i = 0; i < numTests; ++i)
    {
        int arrSize = Rand.next(600'000, 700'000);
        int *arr = new int[arrSize];
        for (int i = 0; i < arrSize; ++i)
        {
            arr[i] = Rand.next(-600'000, 700'000);
        }

        // iterativeQuicksort(arr, 0, arrSize);
        quicksort(arr, 0, arrSize);
        VERIFY_SORTED_ARRAY(arr, arrSize);

        std::cout << "End of test " << i+1 << ".\n";
        delete[] arr;
    }
}

#define quick_sort_h
#endif