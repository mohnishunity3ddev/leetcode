#include <iostream>
#include <vector>

#include <defines.h>
#include <leetcode/bit_manipulation/0191_number_of_1_bits.h>
#include <string>

using namespace std;


int
main()
{
    solution sol;

    uint32_t result = sol.hammingWeight(0b00000000000000000000000000001011);
    cout << result << endl;
}
