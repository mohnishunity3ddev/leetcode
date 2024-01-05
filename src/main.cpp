#include <iostream>
#include <vector>

#include <defines.h>
#include <sorting/sort.h>

using namespace std;
#define RAND_ARR 1

void
writeToFile(const int *originalArray, const int *resultArray, int size)
{
    FILE *f = fopen("error_array.txt", "wb");
    if(f == nullptr) {
        std::cout << "there was an error opening file!\n";
        return;
    }

    char orig[] = "Original Array is: {";
    fwrite(orig, sizeof(orig)-1, 1, f);
    for (i32 i = 0; i < size; ++i) {
        int a = originalArray[i];
        char numChar[32];

        int d = snprintf(numChar, sizeof(numChar), "%d, ", a);

        fwrite(numChar, d, 1, f);
    }
    fseek(f, -2, SEEK_CUR);
    fwrite("}.\n", 3, 1, f);

    char res[] = "Result Array is: {";
    fwrite(res, sizeof(res)-1, 1, f);
    for (i32 i = 0; i < size; ++i) {
        int a = resultArray[i];
        char numChar[32];

        int d = snprintf(numChar, sizeof(numChar), "%d, ", a);

        fwrite(numChar, d, 1, f);
    }
    // 2 backspaces
    fseek(f, -2, SEEK_CUR);
    fwrite("}.\n", 3, 1, f);

    fclose(f);
    std::cout << "There was an error. The array has been written to file!\n";
}

int
main()
{
#if !RAND_ARR
    // i32 arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 99, 30, 29, 101};
    // i32 arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    i32 arr[] = {9,  18, 13, 14, 2,  18, 15, 17, 6,  3,  5,  4,  1,  9,  13,
                 1,  7,  11, 8,  9,  1,  6,  5,  13, 6,  18, 6,  16, 19, 6,
                 7,  10, 13, 3,  13, 17, 14, 5,  3,  13, 15, 12, 13, 4,  10,
                 14, 16, 6,  4,  8,  1,  14, 19, 13, 17, 6,  14, 14, 12, 8};
    // i32 arr[] = {8, 3, 7, 4, 9, 2, 6, 5, 1};
    i32 size = ARRAY_SIZE(arr);

    // std::cout << "Origin Array is: [";
    // for(i32 i = 0; i < size; ++i) {
    //     std::cout << arr[i] << ", ";
    // }
    // std::cout << "\b\b].\n";

    mergeSort(arr, size);

    int flag = 0;
    for (i32 i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = 1;
            break;
        }
    }

    if(flag) {
        ASSERT(0);
    }

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
        i32 size = Rand.next(9, 10'000'000);
        // i32 size = 10'000'000;
        // i32 size = 60;
        int *arr = new int[size];
        int *orig = new int[size];

        for (i32 i = 0; i < size; ++i) {
            arr[i] = Rand.next(1, 1'000'000);
            orig[i] = arr[i];
        }

        quicksort(arr, 0, size);
        // mergeSort(arr, size);

#if 1
        i32 count = 0;
        for (i32 i = 0; i < size-1; ++i, ++count) {
            if(arr[i] > arr[i+1]) {
                flag = 1;
                break;
            }
        }
        if(flag || count != size-1) {
            writeToFile(orig, arr, size);
            return -1;
        }
        ASSERT(count == size - 1);
        // std::cout << "array size is: " << size
        //           << " and count value is: " << count << "\n";
        if(flag) {
            ASSERT(!"Break");
            std::cout << "Test " << testIndex << " failed!\n";
            break;
        } else {
            std::cout << "Test " << testIndex << " passed!\n";
        }
#endif
        // std::cout << "Test " << testIndex << " passed!\n";

        delete[] arr;
    }

    if(flag) {
        std::cout << "FAILURE!!!\n";
    } else {
        std::cout << "SUCCESS!!!\n";
    }
#endif
}
