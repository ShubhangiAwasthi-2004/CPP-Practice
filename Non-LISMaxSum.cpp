// Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

// Examples:

// Input: arr[] = [4, 6, 1, 2, 3, 8]
// Output: 10
// Explanation: The elements which are not in LIS is 4 and 6.
// Input: arr[] = [5, 4, 3, 2, 1]
// Output: 14
// Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
// Constraints:
// 1 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 105


class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
       int n = arr.size();
        vector<int> dp(n, 1);
        int maxLen = 1;

        // Step 1: Standard LIS DP
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        // Step 2: Find LIS with maxLen and minimal sum (just one such LIS)
        int lisSum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                // Reconstruct LIS ending at i
                vector<int> lis;
                lis.push_back(arr[i]);
                int val = arr[i], len = maxLen - 1;

                for (int j = i - 1; j >= 0 && len > 0; --j) {
                    if (arr[j] < val && dp[j] == len) {
                        lis.push_back(arr[j]);
                        val = arr[j];
                        len--;
                    }
                }

                int sum = 0;
                for (int k : lis) sum += k;
                lisSum = min(lisSum, sum);  // pick smallest sum LIS
            }
        }

        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        return totalSum - lisSum;
    }
};
