// Given a garden with n flowers planted in a row, that is represented by an array arr[], where arr[i] denotes the height of the ith flower.You will water them for k days. In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit. You have to maximize the minimum height of all flowers after  k days of watering.

// Examples:

// Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
// Output: 2
// Explanation: The minimum height after watering is 2.
// Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
// Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]
// Input: arr[] = [5, 8], k = 5, w = 1
// Output: 9
// Explanation: The minimum height after watering is 9.
// Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
// Day 5: Water the second flower -> arr becomes [9, 9]
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ w ≤ arr.size()
// 1 ≤ k ≤ 105
// 1 ≤ arr[i] ≤ 109


class Solution {
public:
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        int low = getMin(arr);
        int high = low + k;
        int answer = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }

private:
    bool isPossible(vector<int>& arr, int k, int w, int targetHeight) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        long long added = 0;
        long long totalUsed = 0;

        for (int i = 0; i < n; ++i) {
            added += diff[i];
            long long currentHeight = arr[i] + added;

            if (currentHeight < targetHeight) {
                long long need = targetHeight - currentHeight;
                totalUsed += need;
                if (totalUsed > k) return false;

                diff[i] += need;
                if (i + w < diff.size()) {
                    diff[i + w] -= need;
                }
                added += need;
            }
        }

        return true;
    }

    int getMin(const vector<int>& arr) {
        int minVal = INT_MAX;
        for (int val : arr) {
            minVal = min(minVal, val);
        }
        return minVal;
    }
};
