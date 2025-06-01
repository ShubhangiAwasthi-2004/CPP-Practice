// Given two matrices mat1[][] and mat2[][] of size n x n, where the elements in each matrix are arranged in strictly ascending order.
// Specifically, each row is sorted from left to right, and the last element of a row is smaller than the first element of the next row.
// You're given a target value x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where the sum of a + b is equal to x.

// Examples:

// Input: n = 3, x = 21,
// mat1[][] = [[1, 5, 6], [8, 10, 11], [15, 16, 18]],
// mat2[][] = [[2, 4, 7], [9, 10, 12], [13, 16, 20]]
// OUTPUT: 4
// Explanation: The pairs whose sum is found to be 21 are (1, 20), (5, 16), (8, 13) and (11, 10).
// Input: n = 2, x = 10,
// mat1[][] = [[1, 2], [3, 4]]
// mat2[][] = [[4, 5], [6, 7]]
// Output: 2
// Explanation: The pairs whose sum found to be 10 are (4, 6) and (3, 7).

// Constraints:
// 1 ≤ n ≤ 100
// 1 ≤ x ≤ 105
// 1 ≤ mat1[i][j] , mat2[i][j] ≤ 105

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
         unordered_set<int> mat2_elements;
        int count = 0;
        int n = mat1.size();
        
        // Store all elements of mat2 in a set for fast lookup
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat2_elements.insert(mat2[i][j]);

        // For each element in mat1, check if x - mat1[i][j] exists in mat2
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mat2_elements.find(x - mat1[i][j]) != mat2_elements.end())
                    ++count;

        return count;
    }
};

