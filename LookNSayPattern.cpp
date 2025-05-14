// Given an integer n. Return the nth row of the following look-and-say pattern.
// 1
// 11
// 21
// 1211
// 111221
// Look-and-Say Pattern:

// To generate a member of the sequence from the previous member, read off the 
// digits of the previous member, counting the number of digits in groups of the same digit. For example:

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// 1211 is read off as "one 1, one 2, then two 1s" or 111221.
// 111221 is read off as "three 1s, two 2s, then one 1" or 312211.


//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // Base case
        
        string result = "1";
        
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            
            for (int j = 1; j < result.length(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++count;
                } else {
                    current += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            
            current += to_string(count) + result.back(); // Last group
            result = current;
        }
        
        return result;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
