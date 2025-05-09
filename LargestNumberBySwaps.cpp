//Given a number k and string s of digits denoting a positive integer, build the largest 
//number possible by performing swap operations on the digits of s at most k times.

class Solution {
public:
    string maxNum;

    void helper(string &s, int k, int idx) {
        if (k == 0) return;

        char maxDigit = s[idx];
        for (int i = idx + 1; i < s.size(); i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        if (maxDigit != s[idx]) {
            k--; // A swap will be made
        }

        for (int i = s.size() - 1; i > idx; i--) {
            if (s[i] == maxDigit) {
                swap(s[idx], s[i]);
                if (s > maxNum) {
                    maxNum = s;
                }
                helper(s, k, idx + 1);
                swap(s[idx], s[i]); // backtrack
            }
        }

        // Also proceed without swap if maxDigit == s[idx]
        if (maxDigit == s[idx]) {
            helper(s, k, idx + 1);
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        helper(s, k, 0);
        return maxNum;
    }
};
