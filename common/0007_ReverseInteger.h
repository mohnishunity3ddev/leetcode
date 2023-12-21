#if !defined(REVERSEINTEGER_H)

#include "defines.h"
#include <cstdio>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        unsigned int uNum = (unsigned int)abs(x);
        bool negative = (x < 0);
        unsigned int temp = 0;

        unsigned int ceiling = ((unsigned int)(~(1 << 31))) / 10;

        while(uNum != 0) {
            unsigned int i = uNum % 10;
            temp = temp*10 + i;

            if((uNum > 10) && (temp > ceiling)) {
                printf("ceiling touched!\n");
                temp = 0;
                break;
            }

            uNum /= 10;
        }

        int result = 0;
        if(temp > 0) {
            result = (int)temp;
            result *= negative ? -1 : 1;
        }

        return result;
    }

    void
    driver()
    {
        int i = -2147483412; // 2143847412
        int result = reverse(i);
        printf("the reverse of %d is %d.\n", i, result);
    }
};


#define REVERSEINTEGER_H
#endif // REVERSEINTEGER_H