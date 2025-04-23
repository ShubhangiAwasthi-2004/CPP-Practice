//Given an array arr[] containing 2*n + 2 positive numbers,
//out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct.
//Find the other two numbers. Return the answer in increasing order.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        for (int num : arr)
            xor_all ^= num;

        // Get rightmost set bit (diff bit between the two unique numbers)
        int set_bit = xor_all & -xor_all;

        int x = 0, y = 0;
        for (int num : arr) {
            if (num & set_bit)
                x ^= num; // XOR of one group
            else
                y ^= num; // XOR of other group
        }

        // Return in increasing order
        if (x < y)
            return {x, y};
        else
            return {y, x};
    }
};
