// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array,
// the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [5, -2, 3, 4]
// Output: 12
// Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -104 ≤ arr[i] ≤ 104

class Solution {
  public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();

        // Standard Kadane's for max subarray sum (non-wrapping)
        int max_kadane = kadane(arr);

        // Find total array sum
        int total_sum = 0;
        for (int i = 0; i < n; i++)
            total_sum += arr[i];

        // Invert array elements to find min subarray sum
        for (int i = 0; i < n; i++)
            arr[i] = -arr[i];

        // Apply Kadane’s on inverted array to get min subarray sum
        int max_inverted_kadane = kadane(arr);

        // Restore array elements
        for (int i = 0; i < n; i++)
            arr[i] = -arr[i];

        int max_wrap = total_sum + max_inverted_kadane;

        // If all numbers are negative, max_wrap becomes 0 or less
        if (max_wrap == 0) return max_kadane;

        return max(max_kadane, max_wrap);
    }

private:
    int kadane(vector<int>& arr) {
        int max_end_here = arr[0], max_so_far = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            max_end_here = max(arr[i], max_end_here + arr[i]);
            max_so_far = max(max_so_far, max_end_here);
        }
        return max_so_far;
    }
};
