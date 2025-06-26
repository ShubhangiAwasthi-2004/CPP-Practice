// Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

// The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

// Examples :

// Input: s = "abbccc", k = 2
// Output: 6
// Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
// Input: s = "aaab", k = 2
// Output: 2
// Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
// Constraints:
// 0 ≤ k ≤ s.length() ≤ 105 


class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char, int> freq;

        // Count frequencies
        for (char ch : s)
            freq[ch]++;

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (auto &entry : freq)
            pq.push(entry.second);

        // Remove k characters
        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            top--; // remove one character
            if (top > 0)
                pq.push(top);
        }

        // Calculate final value
        int result = 0;
        while (!pq.empty()) {
            int f = pq.top();
            pq.pop();
            result += f * f;
        }

        return result;
    }
};
