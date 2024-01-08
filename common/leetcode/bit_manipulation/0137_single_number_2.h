#if !defined(number_of_1_bits)

// Given an integer array nums where every element appears three times except
// for one, which appears exactly once. Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

#include <stdint.h>
#include <vector>

using namespace std;

class solution
{
  public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int i=0; i < 32; ++i) {
            int sum = 0;
            for(int n = 0; n < nums.size(); ++n) {
                sum += ((nums[n] >> i) & 0x1);
            }

            if(sum % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};

#define number_of_1_bits
#endif