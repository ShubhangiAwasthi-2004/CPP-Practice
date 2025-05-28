// Given an n x m binary matrix mat[][] containing only 0s and 1s, 
// determine if there exists a rectangle within the matrix such that all four corners 
// of the rectangle are 1. If such a rectangle exists, return true; otherwise, return false.

// Example:
// Input: mat[][] =
// [[1, 0, 0, 1, 0],
// [0, 0, 1, 0, 1],
// [0, 0, 0, 1, 0], 
// [1, 0, 1, 0, 1]] 
// Output: true
// Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4) 

// Constraints:
// 1 <= n, m <= 200
// 0 <= mat[i] <= 1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();
        
        // Set to store seen column pairs
        unordered_set<string> seen;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (mat[i][j] == 1) {
                    for (int k = j + 1; k < m; ++k) {
                        if (mat[i][k] == 1) {
                            // Column pair with 1s in current row
                            string key = to_string(j) + "," + to_string(k);
                            if (seen.count(key)) {
                                // Found a rectangle
                                return true;
                            }
                            // Mark this column pair seen for future rows
                            seen.insert(key);
                        }
                    }
                }
            }
        }
        return false;
    }
};
