#if !defined(STRINGTOINTEGER_ATOI_H)

#include <string>
#include <cstdio>
#include <limits>
#include <cmath>

using namespace std;

class Solution
{
  public:
    int
    myAtoi(string s)
    {
        int len = s.size();
        int i = 0;
        bool positive = true;
        while ((s[i] == ' ') && (i < len)) {
            ++i;
        }

        if((i < len) && ((s[i] == '-') || (s[i] == '+'))) {
            if(s[i] == '-') {
                positive = false;
            }
            ++i;
        }

        int result = 0;
        int digitArray[256];
        int digitCount = 0;
        bool limitCrossed = false;
        bool gotFirstNonZero = false;
        int maxInt = numeric_limits<int>::max();
        int minInt = numeric_limits<int>::min();
        while ((i < len)) {
            char c = s[i++];
            if(c < '0' || c > '9') {
                break;
            }
            int n = (int)(c - '0');

            if((n == 0) && !gotFirstNonZero) {
                continue;
            }
            else {
                gotFirstNonZero = true;
                digitArray[digitCount++] = n;
                if((digitCount-1) > 9) {
                    if (positive) result = maxInt;
                    else result = minInt;
                    return result;
                }
            }
        }

        int digitIndex = 0;
        int sign = positive ? 1 : -1;
        while (digitIndex < digitCount)
        {
            int mul = pow(10, ((digitCount-1) - digitIndex));
            int d = digitArray[digitIndex++];
            int num = d*mul;
            int temp = result + num*sign;

            if(positive && (temp < result)) {
                // ASSERT(0);
                limitCrossed = true;
                break;
            }
            else if(!positive && (temp > result))
            {
                // ASSERT(0);
                limitCrossed = true;
                break;
            }
            result = temp;
        }

        if(limitCrossed)
        {
            if (positive) result = maxInt;
            else result = minInt;
        }
        return result;
    }

    void
    driver()
    {
        int a = 0;
        string s = "2147483648";
        int res = myAtoi(s);
        printf("the num is %d\n", res);

#ifdef HAS_UBSAN
        printf("HAS UBSAN!\n");
#else
        printf("DOES NOT HAVE UBSAN!\n");
#endif
    }
};

#define STRINGTOINTEGER_ATOI_H
#endif // 08_STRINGTOINTEGER(ATOI)_H