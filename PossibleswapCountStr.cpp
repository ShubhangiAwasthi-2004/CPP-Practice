// Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

// Examples:

// Input: s = "geek"
// Output: 6
// Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
// Input: s = "aaaa"
// Output: 1
// Explanation: Only one distinct string is possible after one swap(i.e "aaaa")
// Constraints:
// 2 ≤ s.size() ≤ 104

class Solution {
  public:
    int countStrings(string &s) {
        // code here
          int n=s.length();
        unordered_map<char,int>map;
        for(auto i:s)
        map[i]++;
        int ans=(n*(n-1))/2;
        int diff=0;
        for(auto i:map)
        {
            if(i.second>1)
            {
                int len=i.second;
                diff+=(len*(len-1))/2;
            }
        }
        if(diff>0)
        return ans-diff+1;
        return ans;
    }
};
