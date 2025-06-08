// Given a string s consisting of digits, determine whether it can be classified as a sum-string.

// A sum-string is a string that can be split into more than two non-empty substrings such that:


// The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

// This condition must apply recursively to the substrings before it.

// The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

// Examples:

// Input: s = "12243660"
// Output: true
// Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
// 36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
// Input: s = "1111112223"
// Output: true
// Explanation: Split the string as {"1", "111", "112", "223"}, where:
// 112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
// Input: s = "123456"
// Output: false
// Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
// Constraints:
// 1 ≤ s.size() ≤ 100
// String consists of characters from '0' to '9'.


class Solution {
  public:
    // Helper function to add two numbers represented as strings
    string stringSum(string a, string b) {
        string res;
        int carry = 0, sum = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? a[i--] - '0' : 0;
            int digit2 = (j >= 0) ? b[j--] - '0' : 0;
            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // Recursive check function
    bool isValid(string &s, int start, string a, string b) {
        string sum = stringSum(a, b);
        int sumLen = sum.size();

        if (start + sumLen > s.size() || s.substr(start, sumLen) != sum)
            return false;

        if (start + sumLen == s.size())
            return true;

        return isValid(s, start + sumLen, b, sum);
    }

    bool isSumString(string &s) {
        int n = s.size();
        // Try all combinations for first and second number
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; i + j < n; ++j) {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                
                // Leading zero check
                if ((a[0] == '0' && a.length() > 1) || (b[0] == '0' && b.length() > 1))
                    continue;

                if (isValid(s, i + j, a, b))
                    return true;
            }
        }
        return false;
    }
};
