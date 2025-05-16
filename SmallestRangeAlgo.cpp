// Given a 2d integer array arr[][] of size k*n, where each row is sorted in ascending order.
// Your task is to find the smallest range [l, r] that includes at least one element from each of the k lists.
// If more than one such ranges are found, return the first one.

// Examples:
// Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
// Output: [6, 8]
// Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.

// Constraints:
// 1 <= k, n <= 500
// 0 <= arr[ i ] <= 105


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
         int k = arr.size();  // number of lists
        int n = arr[0].size(); // size of each list (assumed same)
        
        // Min-heap: stores {value, list_index, element_index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxi = INT_MIN;
        
        // Initialize heap with first element from each list
        for (int i = 0; i < k; i++) {
            pq.push({arr[i][0], i, 0});
            maxi = max(maxi, arr[i][0]);
        }
        
        int start = 0, end = INT_MAX;
        
        while (true) {
            auto curr = pq.top();
            pq.pop();
            int mini = curr[0];
            int row = curr[1];
            int col = curr[2];
            
            // Update the range if it's smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
            // If there are more elements in the same row, push the next
            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                pq.push({nextVal, row, col + 1});
                maxi = max(maxi, nextVal);
            } else {
                // One of the lists has been exhausted
                break;
            }
        }
        
        return {start, end};
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
