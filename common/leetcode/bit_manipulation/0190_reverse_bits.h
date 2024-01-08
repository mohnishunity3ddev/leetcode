#if !defined(reverse_bits_h)

#include <stdint.h>
#include <string>

class solution{
  public:
    uint32_t
    reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i)
        {
            bool set = (n >> i) & 0x1;
            result += set * (1 << (31 - i));
        }
        return result;
    }
};

#define reverse_bits_h
#endif
