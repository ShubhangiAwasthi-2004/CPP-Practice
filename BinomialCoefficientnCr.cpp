// Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

// A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n 
// that gives the number of ways to choose r objects from a set of n objects without considering the order.
// The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
// Note: If r is greater than n, return 0.
// It is guaranteed that the value of nCr will fit within a 32-bit integer.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
         if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        int C[r + 1];
        memset(C, 0, sizeof(C));
        C[0] = 1; // Base case: nC0 = 1

        // Use Pascal's Triangle logic
        for (int i = 1; i <= n; i++) {
            // Compute next row of Pascal Triangle
            for (int j = std::min(i, r); j > 0; j--)
                C[j] = C[j] + C[j - 1];
        }

        return C[r]; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
