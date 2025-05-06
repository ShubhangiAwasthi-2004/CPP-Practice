//Given a string s of lowercase English alphabets, your task is to return the maximum number of substrings formed,
//after possible partitions (probably zero) of s such that no two substrings have a common character.

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();
        
        // Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }
        
        int partitions = 0, end = 0;
        
        for (int i = 0; i < n; i++) {
            end = max(end, lastIndex[s[i]]); // Expand to the farthest last occurrence
            if (i == end) { // A valid partition is found
                partitions++;
            }
        }
        
        return partitions;
        
    }
};
