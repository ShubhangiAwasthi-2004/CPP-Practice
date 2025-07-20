// You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive 
// integers can be formed such that at least one digit from the array arr[] appears in the number.

// Examples:

// Input: n = 1, arr[] = [1, 2, 3]
// Output: 3
// Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
// Input: n = 2, arr[] = [3, 5]
// Output: 34
// Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].
// Constraints:
//   1 ≤ n ≤ 9
//   1 ≤ arr.size() ≤ 10
//   0 ≤ arr[i] ≤ 9

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
         set<int> allowed(arr.begin(), arr.end());
        string maxNum(n, '9'); // highest n-digit number like "999..." of length n
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
        
        function<int(int, bool, bool, bool)> dfs = [&](int pos, bool tight, bool leadingZero, bool hasDigit) {
            if (pos == n) return hasDigit ? 1 : 0;
            if (dp[pos][tight][leadingZero][hasDigit] != -1) return dp[pos][tight][leadingZero][hasDigit];

            int limit = tight ? (maxNum[pos] - '0') : 9;
            int res = 0;

            for (int d = 0; d <= limit; ++d) {
                bool nextTight = tight && (d == limit);
                bool nextLeadingZero = leadingZero && (d == 0);
                bool nextHasDigit = hasDigit || (!nextLeadingZero && allowed.count(d));

                // skip leading zero at the beginning
                if (pos == 0 && d == 0) continue;

                res += dfs(pos + 1, nextTight, nextLeadingZero, nextHasDigit);
            }

            return dp[pos][tight][leadingZero][hasDigit] = res;
        };

        return dfs(0, true, true, false);
    }
};
