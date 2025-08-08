class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int len = 0; // length of the previous longest prefix suffix

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            } else {
                lps[i] = 0;
            }
        }
        return lps[n - 1]; // Last value is the length of longest prefix which is also suffix
    }
};
