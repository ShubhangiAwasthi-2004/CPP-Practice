// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

// Note : If no such substring exists, return -1. 

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.
// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
// Constraints:
// 1 ≤ s.size() ≤ 105
// 1 ≤ k ≤ 26

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         // code here
        int n=s.size();
        int i=0;
        int st=0;
        int ans = -1;
        unordered_map<char,int>mp;
        while(i<n)
        {
            mp[s[i]]++;
            while(mp.size()>k)
            {
                mp[s[st]]--;
                if(mp[s[st]]==0)
                {
                    mp.erase(s[st]);
                }
                st++;
            }
            i++;
            if(mp.size()==k)
            {
                ans=max(ans,i-st);
            }
        }
        return ans;
    }
};
