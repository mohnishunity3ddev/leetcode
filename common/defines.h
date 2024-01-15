#if !defined(DEFINES_H)

#include <random>

#define ARRAY_SIZE(arr) sizeof((arr))/sizeof((arr)[0])

#define ASSERT(EXP)                                                            \
    if (!(EXP))                                                                \
    {                                                                          \
        *((volatile int *)0) = 0;                                              \
    }

#include <stdint.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef float f32;

void
swap(int &a, int &b)
{
    int aXb = a ^ b;
    a ^= aXb;
    b ^= aXb;
}

struct myRand
{
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<i32> distribution;
    int min, max;

    myRand() = delete;
    myRand(int min, int max) : min(min), max(max) {
        gen = std::mt19937(rd());
        distribution = std::uniform_int_distribution<i32>(min, max);
    }

    i32 next() {
        i32 result = distribution(gen);
        return result;
    }

    i32 next(int inclusiveL, int exclusiveR) {
        int d = exclusiveR - inclusiveL;
        if (d <= 0) {
            d = 1;
        }
        i32 rand = next();
        i32 result = inclusiveL + (rand % d);
        return result;
    }

    std::vector<int>
    getUniqueRandomSequence(int min, int max, int maxDiff = 1)
    {
        std::vector<int> sequence;
        for (int i = min; i <= max; i += maxDiff)
        {
            sequence.push_back(i);
        }

        std::shuffle(sequence.begin(), sequence.end(), gen);
        return sequence;
    }
};

myRand Rand(1, 10000000);

#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define ZERO_ARRAY(arr, size)                                                  \
    for (int i = 0; i < (size); ++i)                                           \
    {                                                                          \
        (arr)[i] = 0;                                                          \
    }

// Returns the max value out of all the items in the given array.
// also checks for negative values in the array.
inline int
maxValueInArray(int *arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; ++i)
    {
        int n = arr[i];
        if (n < 0)
        {
            // IMPORTANT: Negatives numbers cannot be sorted using count sort.
            // Error condition.
            return -1;
        }
        if (n > max)
        {
            max = arr[i];
        }
    }

    return max;
}

#define DEFINES_H
#endif