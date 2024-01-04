#if !defined(DEFINES_H)

#define ASSERT(EXP)                                                            \
    if (!(EXP))                                                                \
    {                                                                          \
        *((volatile int *)0) = 0;                                              \
    }

#include <stdint.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef float f32;

#define DEFINES_H
#endif