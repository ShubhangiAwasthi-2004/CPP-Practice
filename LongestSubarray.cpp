// Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

// Examples:
// Input: arr[] = [1, 2, 3, 4, 1], k = 2
// Output: 3
// Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
// Input: arr[] = [6, 5, 3, 4], k = 2
// Output: 4
// Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106
// 0 ≤ k ≤ 106

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> firstIndex; // map of prefix sum to its first index
        int prefix = 0, maxLen = 0;
        
        for (int i = 0; i < n; ++i) {
            // Convert element to 1 or -1
            if (arr[i] > k) prefix += 1;
            else prefix -= 1;

            // If prefix sum is positive from index 0 to i
            if (prefix > 0) {
                maxLen = i + 1;
            } else {
                // If (prefix - 1) was seen before, a subarray with sum > 0 exists
                if (firstIndex.find(prefix - 1) != firstIndex.end()) {
                    maxLen = max(maxLen, i - firstIndex[prefix - 1]);
                }
            }

            // Store the first occurrence of this prefix sum
            if (firstIndex.find(prefix) == firstIndex.end()) {
                firstIndex[prefix] = i;
            }
        }

        return maxLen;
    }
};
