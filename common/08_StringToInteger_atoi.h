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

        while ((i < len) && s[i] == '0') {
            ++i;
        }

        int result = 0;
        int digitArray[256];
        int digitCount = 0;
        int maxInt = ~(1 << 31);
        int minInt = -maxInt - 1;
        while ((i < len)) {
            char c = s[i++];
            if(c < '0' || c > '9') {
                break;
            }
            int n = (int)(c - '0');

            digitArray[digitCount++] = n;
            if((((digitCount-1) > 9) || ((digitCount == 10) && (digitArray[0] > 2)))) {
                if (positive) result = maxInt;
                else result = minInt;
                return result;
            }
        }

        int digitIndex = 0;
        int sign = positive ? 1 : -1;
        bool limitCrossed = false;
        while (digitIndex < digitCount) {
            int mul = pow(10, ((digitCount-1) - digitIndex));
            int d = digitArray[digitIndex++];
            int num = d*mul;
            if(( positive && (result > (maxInt-num))) ||
               (!positive && (result < (minInt+num)))) {
                limitCrossed = true;
                break;
            }
            result += num*sign;
        }

        if(limitCrossed) {
            if (positive) result = maxInt;
            else result = minInt;
        }
        return result;
    }

    void
    driver()
    {
        string s = "      -321321sdfads";
        int res = myAtoi(s);
        printf("the num is %d\n", res);
    }
};

#define STRINGTOINTEGER_ATOI_H
#endif // 08_STRINGTOINTEGER(ATOI)_H