#if !defined(DEFINES_H)

#define ASSERT(EXP)                                                            \
    if (!(EXP))                                                                \
    {                                                                          \
        *((volatile int *)0) = 0;                                              \
    }

#if defined(__has_feature)
#if __has_feature(undefined_behavior_sanitizer)
#define HAS_UBSAN 1
#endif
#endif

#define DEFINES_H
#endif