Given a sorted array arr[] that represents an Arithmetic Progression 
(AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. 
If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.

Examples:

Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.

Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*107


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
       int diff=arr[1]-arr[0];
        
        if(diff>0){
        for(int i=1;i<arr.size()-1;i++)
        {
            int d=arr[i+1]-arr[i];
            if(d==diff) continue;
            if(diff>d) return arr[i]-d;
            else if(diff<d) return arr[i]+diff;
        }
        }
        else{
            for(int i=1;i<arr.size()-1;i++)
           {
            int d=arr[i+1]-arr[i];
            if(d==diff) continue;
            if(diff<d) return arr[i]-d;
            else if(diff>d) return arr[i]+diff;
           }
            
        }
        return *(arr.end()-1)+diff ;
        
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
