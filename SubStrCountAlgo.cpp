// Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.

// Examples:

// Input: s = "abcc", k = 2
// Output: 1
// Explaination: Possible substring of length k = 2 are,
// ab : 2 distinct characters
// bc : 2 distinct characters
// cc : 1 distinct characters
// Only one valid substring so, count is equal to 1.
// Input: "aabab", k = 3
// Output: 3
// Explaination: Possible substring of length k = 3 are, 
// aab : 2 distinct charcters
// aba : 2 distinct characters
// bab : 2 distinct characters
// All these substring are valid so, the total count is equal to 3.
// Constrains:
// 1 ≤ s.size() ≤ 105
// 2 ≤ k ≤ 27


class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        if (k > s.size()) return 0;
        int count = 0;
        unordered_map<char, int> freq;
        
        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            freq[s[i]]++;
        }
        if (freq.size() == k - 1) count++;

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            char out_char = s[i - k];
            char in_char = s[i];

            // Remove the character going out
            freq[out_char]--;
            if (freq[out_char] == 0) freq.erase(out_char);

            // Add the new character
            freq[in_char]++;

            // Check condition
            if (freq.size() == k - 1) count++;
        }

        return count;
    }
};
