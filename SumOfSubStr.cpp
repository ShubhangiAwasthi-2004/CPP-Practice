// Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.

// Note: The number may have leading zeros.
// It is guaranteed that the total sum will fit within a 32-bit signed integer.


class Solution {
  public:
    int sumSubstrings(string &s) {
         long long total_sum = 0, prev_sum = 0;
        int mod = 1000000007; // in case constraints were tight

        for (int i = 0; i < s.length(); ++i) {
            int digit = s[i] - '0';
            prev_sum = prev_sum * 10 + (i + 1) * digit;
            total_sum += prev_sum;
        }

        return (int)total_sum;
        
    }
};
