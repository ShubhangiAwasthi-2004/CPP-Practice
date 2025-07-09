// Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

// Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

// Examples:

// Input: arr[] = [3, 1, 2, 4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
// Input: arr[] = [71, 55, 82, 55]
// Output: 593
// Explanation: The sum of the minimum of all the subarrays is 593.
// Constraints:
// 1 ≤ arr.size() ≤ 3*104
// 1 ≤ arr[i] ≤ 103

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
         int n = arr.size();
        int mod = 1e9 + 7;

        vector<int> prevLess(n), nextLess(n);
        stack<int> s;

        // Previous less (strictly less)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            prevLess[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Next less (less or equal to ensure no double counting)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nextLess[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Now calculate the result
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;
            result += (arr[i] * left * right) % mod;
            result %= mod;
        }

        return (int)result;
    }
};

