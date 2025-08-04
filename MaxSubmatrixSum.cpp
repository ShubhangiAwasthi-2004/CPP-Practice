// Given a 2D matrix mat[][] with dimensions n×m. Find the maximum possible sum of any submatrix within the given matrix.

// Examples:
// Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
// Output: 29
// Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle which is equal to 29.
// Input: mat[][] = [[-1, -2], [-3, -4]]
// Output: -1
// Explanation: Taking only the first cell is the optimal choice.

// Constraints:
// 1 ≤ n, m ≤ 300
// -1000 ≤ mat[i][j] ≤ 1000


class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
         int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Loop over all pairs of rows
        for (int top = 0; top < n; ++top) {
            vector<int> temp(m, 0);

            for (int bottom = top; bottom < n; ++bottom) {
                // Add the current row to temp to form 1D array
                for (int col = 0; col < m; ++col) {
                    temp[col] += mat[bottom][col];
                }

                // Apply Kadane's algorithm on temp
                int currSum = temp[0];
                int maxCurr = temp[0];
                for (int i = 1; i < m; ++i) {
                    currSum = max(temp[i], currSum + temp[i]);
                    maxCurr = max(maxCurr, currSum);
                }

                maxSum = max(maxSum, maxCurr);
            }
        }

        return maxSum;
    }
};
