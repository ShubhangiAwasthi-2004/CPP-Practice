// Given two strings:
// A text string in which you want to search.
// A pattern string that you are looking for within the text.
// Return all positions (1-based indexing) where the pattern occurs as a substring in the text. If the pattern does not occur, return an empty list.
// All characters in both strings are lowercase English letters (a to z).

// Examples:

// Input: text = "birthdayboy", pattern = "birth"
// Output: [1]
// Explanation: The string "birth" occurs at index 1 in text.
// Input: text = "geeksforgeeks", pattern = "geek"
// Output: [1, 9]
// Explanation: The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
// Constraints:
// 1<= text.size() <=5*105
// 1<= pattern.size() <= text.size()

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        vector<int> lps(pat.size(), 0);
        int len = 0, i = 1;

        // Preprocess the pattern (LPS array)
        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Search using KMP
        vector<int> result;
        i = 0; // index for txt
        int j = 0; // index for pat
        while (i < txt.size()) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == pat.size()) {
                result.push_back(i - j + 1); // 1-based index
                j = lps[j - 1];
            } else if (i < txt.size() && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }
};
