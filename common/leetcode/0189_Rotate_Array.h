#pragma once

#include <vector>
#include <iostream>

using namespace std;

inline constexpr void swap(int &a, int &b) {
    int ab = a^b;
    a ^= ab;
    b ^= ab;
}

constexpr void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = k % size;
    if (k == 0) return;

    /*
    ** O(n-k) swaps + O(k) copies + O(k) space.
    */
    int l = size-k;
    vector<int> aux(k);
    for (int i=0; i<k; ++i) aux[i] = nums[l+i];
    for (int i=l-1; i>=0; --i) swap(nums[i], nums[i+k]);
    for (int i=0; i<k; ++i) nums[i] = aux[i];
}

inline void driver() {
    vector<int> ints = {1,2,3,4,5,6,7};
    rotate(ints, 3);

    cout << '[';
    for (const auto& i : ints) {
        cout << i << ", ";
    }    
    cout << "\b\b]" << endl;
}