// There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.


// Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

// Examples :

// Input: n = 1
// Output: 10
// Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
// Input: n = 2
// Output: 36
// Explanation: Possible 2-digit numbers follow keypad moves -
// From 0 → 00, 08 (2), 
// From 1 → 11, 12, 14 (3),
// From 3 → 33, 32, 36 (3), and so on,
// total 36 valid combinations are possible.
// Constraints:
// 1 ≤ n ≤ 15

class Solution {
public:
    int getCount(int n) {
        if (n == 1) return 10;

        vector<vector<int>> moves = {
            {0, 8},        // 0
            {1, 2, 4},     // 1
            {2, 1, 3, 5},  // 2
            {3, 2, 6},     // 3
            {4, 1, 5, 7},  // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9},  // 6
            {7, 4, 8},     // 7
            {8, 5, 7, 9, 0}, // 8
            {9, 6, 8}      // 9
        };

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));

        // Base case: 1-digit numbers (each digit by itself)
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        // Build the DP table
        for (int i = 2; i <= n; i++) {
            for (int digit = 0; digit <= 9; digit++) {
                for (int neighbor : moves[digit]) {
                    dp[i][digit] += dp[i - 1][neighbor];
                }
            }
        }

        // Total sequences of length n starting from any digit
        int total = 0;
        for (int i = 0; i <= 9; i++) {
            total += dp[n][i];
        }

        return total;
    }
};
