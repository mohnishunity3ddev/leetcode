#if !defined(number_of_1_bits)

#include <stdint.h>

class solution
{
  public:
    uint32_t
    hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n != 0) {
            int c = n & 0x1;
            count = count + c;
            n = n >> 1;
        }

        return count;
    }
};

#define number_of_1_bits
#endif