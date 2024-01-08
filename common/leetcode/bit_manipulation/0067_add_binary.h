#if !defined(add_binary_h)

#include <string>
#include <cmath>

using namespace std;

class solution {
  public:
    string
    addBinary(string a, string b)
    {
        string result = "";

        int aLen = a.length() - 1;
        int bLen = b.length() - 1;
        int carry = 0;

        int i, j;
        for (i = aLen, j = bLen; i >= 0 && j >= 0; --i, --j)
        {
            int aIn = a[i] - '0';
            int bIn = b[j] - '0';

            int sum = aIn + bIn + carry;

            carry = sum / 2;
            result = (char)((sum % 2) + '0') + result;
        }

        while(i >= 0)
        {
            int s = ((int)(a[i--] - '0') + carry);
            carry = s/2;
            result = (char)((s % 2) + '0') + result;
        }
        while(j >= 0)
        {
            int s = ((int)(b[j--] - '0') + carry);
            carry = s/2;
            result = (char)((s % 2) + '0') + result;
        }

        if(carry) {
            result = '1' + result;
        }

        return result;
    }
};

#define add_binary_h
#endif