// You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:

// Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
// No substring should have leading zeros.
// Return the minimum number of such pieces the string can be divided into.
// Note: If it is not possible to split the string in this way, return -1.

// Examples:

// Input: s = "101101101"
// Output: 3
// Explanation: The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
// Input: s = "1111101"
// Output: 1
// Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.
// Input: s = "00000"
// Output: -1
// Explanation: There is no substring that can be split into power of 5.
// Constraints:
// 1 ≤ s.size() ≤ 30


class Solution {
  public:
   // Set to store binary representations of powers of 5
    unordered_set<string> power5;

    // DP memoization
    int dp[31];

    // Function to check if a binary string represents a power of 5
    void generatePower5() {
        for (int i = 0; i < 31; ++i) {
            long long num = pow(5, i);
            string bin = "";
            while (num > 0) {
                bin = char('0' + (num % 2)) + bin;
                num /= 2;
            }
            power5.insert(bin);
        }
    }

    int solve(string &s, int start) {
        if (start == s.size()) return 0;
        if (dp[start] != -1) return dp[start];

        int minCuts = INT_MAX;

        for (int end = start; end < s.size(); ++end) {
            string sub = s.substr(start, end - start + 1);
            if (sub[0] == '0') break; // Leading zeros are not allowed

            if (power5.count(sub)) {
                int next = solve(s, end + 1);
                if (next != INT_MAX) {
                    minCuts = min(minCuts, 1 + next);
                }
            }
        }

        return dp[start] = minCuts;
    }

    int cuts(string s) {
        generatePower5();
        memset(dp, -1, sizeof(dp));
        int result = solve(s, 0);
        return result == INT_MAX ? -1 : result;
    }
};
