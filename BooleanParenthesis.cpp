You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.


class Solution {
  public:
  unordered_map<string, int> dp;

    int countWaysUtil(string &s, int l, int r, bool isTrue) {
        if (l > r) return 0;  // Invalid case

        // Single character case
        if (l == r) {
            if (isTrue) return s[l] == 'T';
            else return s[l] == 'F';
        }

        // Memoization key
        string key = to_string(l) + "_" + to_string(r) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;
        for (int k = l + 1; k < r; k += 2) {  // Operators at odd indices
            int leftTrue = countWaysUtil(s, l, k - 1, true);
            int leftFalse = countWaysUtil(s, l, k - 1, false);
            int rightTrue = countWaysUtil(s, k + 1, r, true);
            int rightFalse = countWaysUtil(s, k + 1, r, false);

            if (s[k] == '&') {
                if (isTrue)
                    ways += (leftTrue * rightTrue);
                else
                    ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
            } 
            else if (s[k] == '|') {
                if (isTrue)
                    ways += (leftTrue * rightTrue) + (leftFalse * rightTrue) + (leftTrue * rightFalse);
                else
                    ways += (leftFalse * rightFalse);
            } 
            else if (s[k] == '^') {
                if (isTrue)
                    ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else
                    ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }

        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return countWaysUtil(s, 0, s.size() - 1, true);
    }
};
