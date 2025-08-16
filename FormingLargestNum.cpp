// Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, 
// it results in the largest possible number. Since the result may be very large, return it as a string.

// Examples:
// Input: arr[] = [3, 30, 34, 5, 9]
// Output: 9534330
// Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] gives the largest value.
// Input: arr[] = [54, 546, 548, 60]
// Output: 6054854654
// Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] gives the largest value.
// Input: arr[] = [3, 4, 6, 5, 9]
// Output: 96543
// Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] gives the largest value.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 105


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLargest(vector<int> &arr) {
        // Convert all numbers to strings
        vector<string> nums;
        nums.reserve(arr.size());
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Custom comparator
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            return a + b > b + a; // Put a before b if ab is greater than ba
        });

        // If the largest element is "0", the whole number is 0
        if (nums[0] == "0") return "0";

        // Concatenate result
        string result;
        for (auto &num : nums) {
            result += num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {3, 30, 34, 5, 9};
    cout << sol.findLargest(arr1) << endl; // Output: 9534330

    vector<int> arr2 = {54, 546, 548, 60};
    cout << sol.findLargest(arr2) << endl; // Output: 6054854654

    vector<int> arr3 = {3, 4, 6, 5, 9};
    cout << sol.findLargest(arr3) << endl; // Output: 96543
}
