// You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:
// 0 ≤ i < j < arr.size()
// arr[i] > 2 * arr[j]

// Examples:
// Input: arr[] = [3, 2, 4, 5, 1, 20]
// Output: 3
// Explanation:
// The Reverse pairs are 
// (0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1 
// (2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1 
// (3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1 
// Input: arr[] = [5, 4, 3, 2, 2]
// Output: 2
// Explanation:
// The Reverse pairs are
// (0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
// (0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2

// Constraints:
// 1 ≤ arr.size() ≤ 5*104
// 1 ≤ arr[i] ≤ 109

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return count;
    }

    int mergeSortAndCount(vector<int> &arr, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
        return count;
    }

    int countRevPairs(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
