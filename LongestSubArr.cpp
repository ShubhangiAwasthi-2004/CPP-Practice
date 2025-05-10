//Longest Sub array.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
          int n = arr.size();
        unordered_map<int, int> first_occurrence;
        int max_len = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            // Convert the element
            if (arr[i] > k)
                sum += 1;
            else
                sum -= 1;

            // If sum is positive, the whole array from 0 to i is valid
            if (sum > 0) {
                max_len = i + 1;
            } else {
                // If (sum - 1) has occurred before, that subarray has a positive net count
                if (first_occurrence.find(sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[sum - 1]);
                }
            }

            // Store the first occurrence of this sum
            if (first_occurrence.find(sum) == first_occurrence.end()) {
                first_occurrence[sum] = i;
            }
        }

        return max_len;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
