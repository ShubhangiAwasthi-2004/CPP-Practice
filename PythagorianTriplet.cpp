// Given an array arr[], return true if there is a triplet (a, b, c) from the array 
// (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

// Examples:

// Input: arr[] = [3, 2, 4, 6, 5]
// Output: true
// Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> squares;
        int n = arr.size();

        // Insert all squares into the set
        for (int i = 0; i < n; ++i) {
            squares.insert(arr[i] * arr[i]);
        }

        // Check for any pair (a, b) such that a² + b² exists in set
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if (squares.find(sum) != squares.end()) {
                    return true;
                }
            }
        }

        return false;
    }
};
