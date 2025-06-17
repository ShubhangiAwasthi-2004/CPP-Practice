// You are given an array arr[] of integers, where each element represents the number of coins in a pile. You are also given an integer k.
// Your task is to remove the minimum number of coins such that the absolute difference between the number of coins in any two updated piles is at most k.

// Note: You can also remove a pile by removing all the coins of that pile.

// Examples:

// Input: arr[] = [2, 2, 2, 2], k = 0
// Output: 0
// Explanation: For any two piles the difference in the number of coins is <= 0. So no need to remove any coin. 
// Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
// Output: 2
// Explanation: If we remove one coin each from both the piles containing 5 coins, then for any two piles the absolute difference in the number of coins is <= 3. 
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104
// 0 ≤ k ≤ 104

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // Prefix sum of coins
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Suffix sum of coins
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + arr[i];
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int base = arr[i];
            int maxAllowed = base + k;

            // Binary search to find first element > maxAllowed
            int idx = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin();

            // Remove all coins from piles left of i
            long long removeLeft = prefix[i];

            // Remove coins > maxAllowed
            int numRight = n - idx;
            long long totalRight = suffix[idx];
            long long targetRight = 1LL * numRight * maxAllowed;
            long long removeRight = totalRight - targetRight;

            ans = min(ans, removeLeft + removeRight);
        }

        return (int)ans;
    }
};
