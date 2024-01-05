#include <iostream>
#include <vector>

#include <defines.h>
#include <sorting/sort.h>

using namespace std;
#define RAND_ARR 0

int
main()
{
#if !RAND_ARR
    // i32 arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    i32 arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    i32 size = ARRAY_SIZE(arr);
    quicksort(arr, 0, size);

    std::cout << "Sorted Array is: [";
    for(i32 i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b].\n";

#else
    i32 flag = 0;
    i32 nTests = 1000;
    std::cout << "running " << nTests << " tests.\n";

    for (i32 testIndex = 0; testIndex < nTests; ++testIndex)
    {
        // i32 size = Rand.next(900000, 1000000);
        i32 size = 1'000'000;
        int *arr = new int[size];

        for (i32 i = 0; i < size; ++i) {
            arr[i] = Rand.next();
        }

        quicksort(arr, 0, size);

        i32 count = 0;
        for (i32 i = 0; i < size-1; ++i, ++count) {
            if(arr[i] > arr[i+1]) {
                flag = 1;
                break;
            }
        }
        ASSERT(count == size - 1);
        // std::cout << "array size is: " << size
        //           << " and count value is: " << count << "\n";
        if(flag) {
            std::cout << "Test " << testIndex << " failed!\n";
            break;
        } else {
            std::cout << "Test " << testIndex << " passed!\n";
        }

        delete[] arr;
    }

    if(flag) {
        std::cout << "FAILURE!!!\n";
    } else {
        std::cout << "SUCCESS!!!\n";
    }
#endif
}
