#include <iostream>
#include <vector>

#include <defines.h>
#include <leetcode/bit_manipulation/0067_add_binary.h>
#include <string>

using namespace std;


int
main()
{
    solution sol;
    string a = "101000001001001101100100000101011110110110011011101111111111010"
               "00000101111001110001111100001101";
    string b = "110101001011101110001111100110001010100001101011101010000011011"
               "011001011101111001100000011011110011";
    string result = sol.addBinary(a, b);
    cout << result << endl;
}
