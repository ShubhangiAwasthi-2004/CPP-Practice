Given a string str, your task is to find the length of the smallest window
that contains all the characters of the given string at least once.

class Solution {
  public:
    int findSubString(string& str) {
         unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();

        unordered_map<char, int> window_freq;
        int min_len = INT_MAX;
        int start = 0, count = 0;

        for (int end = 0; end < str.length(); end++) {
            window_freq[str[end]]++;
            if (window_freq[str[end]] == 1) count++; // New unique char added

            while (count == total_unique) {
                min_len = min(min_len, end - start + 1);
                window_freq[str[start]]--;
                if (window_freq[str[start]] == 0) count--; // Unique char removed
                start++;
            }
        }

        return min_len;
        
    }
};
