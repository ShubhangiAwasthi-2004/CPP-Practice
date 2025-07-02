// Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.

// Examples:

// Input: arr[] = [2, 1, 2]
// Output: 3
// Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5
// Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < arr.size(); ++right) {
            freq[arr[right]]++;

            // If we have more than two distinct elements, shrink the window
            while (freq.size() > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // Update the maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
