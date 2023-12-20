#if !defined(MedianTwoSorted_H)

// NOTE: https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <vector>
#include <cstdio>

using namespace std;

class Solution
{
  public:
    double
    findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int merged[2048];
        int c1 = 0, c2 = 0, mergeCount = 0;
        while((c1 < size1) && (c2 < size2)) {
            int n1 = nums1[c1];
            int n2 = nums2[c2];
            int n = 0;
            if(n1 < n2) {
                n = n1;
                ++c1;
            }
            else {
                n = n2;
                ++c2;
            }
            merged[mergeCount++] = n;
        }

        while(c1 < nums1.size()) {
            merged[mergeCount++] = nums1[c1++];
        }
        while(c2 < num2.size()) {
            merged[mergeCount++] = nums2[c2++];
        }

        double result = 0.0;
        if(mergeCount & 0x1) {
            result = merged[mergeCount/2];
        }
        else {
            result = 0.5*(merged[mergeCount/2] + merged[(mergeCount/2) - 1]);
        }

        return result;
    }

    void
    driver()
    {
        vector<int> n1 = {1, 2};
        vector<int> n2 = {3, 4};

        printf("the median of the two sorted arrays is: %f\n", findMedianSortedArrays(n1, n2));
    }
};

#define MedianTwoSorted_H
#endif