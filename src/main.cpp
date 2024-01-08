#include <iostream>
#include <vector>

#include <defines.h>
#include <leetcode/bit_manipulation/0190_reverse_bits.h>
#include <string>

using namespace std;


int
main()
{
    solution sol;

    uint32_t result = sol.reverseBits(0b00111001011110000010100101000000);
    cout << result << endl;
}
