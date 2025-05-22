// Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

// Examples:

// Input: s = "aebcbda"
// Output: 2
// Explanation: Remove characters 'e' and 'd'.

// 13 (length of s) - 5 = 8.
// Constraints:
// 1 ≤ s.size() ≤ 103


class Solution {
  public:
    int minDeletions(string s) {
         int n = s.size();
        // dp[i][j] will store the length of the LPS from index i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // A single character is always a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Build the table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int lpsLength = dp[0][n - 1];
        return n - lpsLength; 
    }
};
