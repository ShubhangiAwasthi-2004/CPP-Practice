// Given a string s consisting of lowercase characters, the task is to find the
// count of all substrings that start and end with the same character.

// Examples:
// 1 -
// Input: s = "abcab"
// Output: 7
// Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
// 2 - 
// Input: s = "aba"
// Output: 4
// Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"

// Constraints:
// 1 <= |s| <= 104
// s contains lower case english alphabets


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
            int freq[26] = {0};

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int count = 0;

        // For each character, apply the formula
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                count += (freq[i] * (freq[i] + 1)) / 2;
            }
        }

        return count;
        
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
