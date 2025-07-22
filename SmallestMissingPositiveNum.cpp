// You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1. The array can have negative integers too.

// Examples:
// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.
// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.
// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// Explanation: Smallest positive missing number is 1.

// Constraints:  
// 1 ≤ arr.size() ≤ 105
// -106 ≤ arr[i] ≤ 106


class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
         int n = arr.size();

        // Place each number in its correct index
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Find the first index where number is not i+1
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers 1 to n are present
        return n + 1;
    }
};
