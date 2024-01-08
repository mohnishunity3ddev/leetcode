#if !defined(add_binary_h)

#include <string>
#include <cmath>

using namespace std;

class solution {
  public:
    string
    addBinary(string a, string b)
    {
        string result;

        unsigned int inputA = 0, inputB = 0;

        int bit = 0;
        for (int i = a.length() - 1, bit = 0; i >= 0; --i, ++bit) {
            inputA += (pow(2, bit) * (unsigned int)(a[i] - '0'));
        }
        for (int i = b.length() - 1, bit = 0; i >= 0; --i, ++bit) {
            inputB += (pow(2, bit) * (unsigned int)(b[i] - '0'));
        }

        unsigned int sum = inputA + inputB;

        unsigned int shift = 0;
        unsigned int n = 2;
        while(n > 1) {
            n = sum >> shift;
            char set = (n & 0x1) ? '1' : '0';
            result = set + result;
            shift++;
        }

        return result;
    }
};

#define add_binary_h
#endif