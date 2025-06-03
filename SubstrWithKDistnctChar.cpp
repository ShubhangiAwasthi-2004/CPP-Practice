// Given a string consisting of lowercase characters and an integer k, the task is to count all possible 
// substrings (not necessarily distinct) that have exactly k distinct characters. 

// Examples :
// Input: s = "abc", k = 2
// Output: 2
// Explanation: Possible substrings are ["ab", "bc"]
// Input: s = "aba", k = 2
// Output: 3
// Explanation: Possible substrings are ["ab", "ba", "aba"]
// Input: s = "aa", k = 1
// Output: 3
// Explanation: Possible substrings are ["a", "a", "aa"]

// Constraints:
// 1 ≤ s.size() ≤ 106
// 1 ≤ k ≤ 26

class Solution {
  public:
   // Helper function to count substrings with at most k distinct characters
    int countAtMostK(string& s, int k) {
        int n = s.size();
        int left = 0, right = 0, count = 0;
        unordered_map<char, int> freq;

        while (right < n) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }

    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
