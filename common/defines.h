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

    i32 next(int l, int r) {
        int d = r - l;
        i32 rand = next();
        i32 result = l + (rand % d);
        return result;
    }
};

myRand Rand(1, 1000000);

#define DEFINES_H
#endif