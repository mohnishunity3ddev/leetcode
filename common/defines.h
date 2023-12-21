#if !defined(DEFINES_H)

#define ASSERT(EXP)                                                            \
    if (!(EXP))                                                                \
    {                                                                          \
        *((volatile int *)0) = 0;                                              \
    }

#define DEFINES_H
#endif