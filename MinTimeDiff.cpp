// Given an array arr[] of time strings in 24-hour clock format "HH:MM:SS", return the minimum difference in seconds between any two time strings in the arr[].
// The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.

// Examples:
// Input: arr[] = ["12:30:15", "12:30:45"]
// Output: 30
// Explanation: The minimum time difference is 30 seconds.
// Input: arr[] = ["00:00:01", "23:59:59", "00:00:05"]
// Output: 2
// Explanation: The time difference is minimum between "00:00:01" and "23:59:59".

// Constraints:
// 2 ≤ arr.size() ≤ 105
// arr[i] is in "HH:MM:SS" format.


class Solution {
  public:
     int timeToSeconds(const string& time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        vector<int> seconds;
        
        // Convert all times to seconds
        for (const string &time : arr) {
            seconds.push_back(timeToSeconds(time));
        }

        // Sort the times in seconds
        sort(seconds.begin(), seconds.end());

        int minDiff = INT_MAX;

        // Find the minimum difference between adjacent times
        for (int i = 1; i < seconds.size(); ++i) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }

        // Check the circular case: difference between last and first
        int wrapAroundDiff = 86400 - seconds.back() + seconds[0]; // 86400 seconds in a day
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
