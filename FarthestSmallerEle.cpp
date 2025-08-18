// You are given an array arr[]. For each element at index i (0-based indexing), find the farthest index j to the right (i.e., j > i) 
// such that arr[j] < arr[i]. If no such index exists for a given position, return -1 for that index. Return the resulting array of answers.

// Examples:
// Input: arr[] = [2, 5, 1, 3, 2]
// Output: [2, 4, -1, 4, -1]
// Explanation: arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
// arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
// arr[2] = 1: No smaller element to the right → -1.
// arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
// arr[4] = 2: No elements to the right → -1.
// Input: arr[] = [2, 3, 5, 4, 1] 
// Output: [4, 4, 4, 4, -1]
// Explanation: arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3].

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106


class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffMin(n), ans(n, -1);

        // Step 1: Build suffix min array
        suffMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }

        // Step 2: For each index, find farthest j using binary search
        for (int i = 0; i < n; i++) {
            int lo = i+1, hi = n-1, res = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (suffMin[mid] < arr[i]) {
                    res = mid;     // valid, but try to go farther
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans[i] = res;
        }

        return ans;
    }
};
