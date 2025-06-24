// Given an array arr[] of distinct positive integers. Your task is to find the largest subset such that for every pair of elements (x, y) in the subset, either x divides y or y divides x.
// Note : If multiple subsets of the same maximum length exist, return the one that is lexicographically greatest, after sorting the subset in ascending order.

// Examples:

// Input: arr[] = [1, 16, 7, 8, 4]
// Output: [1, 4, 8, 16]
// Explanation: The largest divisible subset is [1, 4, 8, 16], where each element divides the next one. This subset is already the lexicographically greatest one.
// Input: arr[] = [2, 4, 3, 8]
// Output: [2, 4, 8]
// Explanation: The largest divisible subset is [2, 4, 8], where each element divides the next one. This subset is already the lexicographically greatest one.
// Constraint:
// 1 ≤ arr.size() ≤ 103
// 1  ≤ arr[i] ≤ 109


class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();

        // Sort in descending order to get lexicographically greatest subset
        sort(arr.rbegin(), arr.rend());

        vector<int> dp(n, 1);       // dp[i] stores length of longest subset ending at i
        vector<int> par(n, -1);     // par[i] stores parent index of i in the subset
        int parent = -1;            // To track index of last element in the largest subset
        int maxi = 0;               // Max length of subset

        // Fill DP and parent arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        par[i] = j;
                    }
                }
            }

            // Update overall max
            if (dp[i] > maxi) {
                maxi = dp[i];
                parent = i;
            }
        }

        // Reconstruct result subset from parent array
        vector<int> res;
        while (parent != -1) {
            res.push_back(arr[parent]);
            parent = par[parent];
        }

        // Already in descending order due to sort(arr.rbegin(), arr.rend())
        // If needed in ascending order: reverse(res.begin(), res.end());

        return res;
    }
};

