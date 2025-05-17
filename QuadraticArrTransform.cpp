// Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C.
// The task is to transform each element x in the array using the quadratic function A*(x2) + B*x + C.
// After applying this transformation to every element, return the modified array in sorted order.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
         auto f = [&](int x) {
            return A * x * x + B * x + C;
        };

        int n = arr.size();
        vector<int> res(n);
        int i = 0, j = n - 1;
        int index = A >= 0 ? n - 1 : 0;

        while (i <= j) {
            int val_i = f(arr[i]);
            int val_j = f(arr[j]);

            if (A >= 0) {
                if (val_i > val_j) {
                    res[index--] = val_i;
                    i++;
                } else {
                    res[index--] = val_j;
                    j--;
                }
            } else {
                if (val_i < val_j) {
                    res[index++] = val_i;
                    i++;
                } else {
                    res[index++] = val_j;
                    j--;
                }
            }
        }

        return res;
        
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
