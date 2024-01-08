#include <iostream>
#include <vector>

#include <defines.h>
#include <leetcode/bit_manipulation/0137_single_number_2.h>

using namespace std;


int
main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    solution sol;
    int res = sol.singleNumber(nums);
    std::cout << res << endl;
}
