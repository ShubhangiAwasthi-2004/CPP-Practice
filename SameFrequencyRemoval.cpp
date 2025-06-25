/*Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the 
frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:
Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.

Constraints:
1 ≤ s.size() ≤ 105
*/

#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
  public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        unordered_map<int, int> freqCount;

        // Step 1: Count frequencies
        for (char ch : s)
            freq[ch]++;

        // Step 2: Count frequency of frequencies
        for (auto it = freq.begin(); it != freq.end(); ++it)
            freqCount[it->second]++;

        // Step 3: Evaluate scenarios
        if (freqCount.size() == 1)
            return true;

        if (freqCount.size() > 2)
            return false;

        auto it = freqCount.begin();
        int f1 = it->first, count1 = it->second;
        ++it;
        int f2 = it->first, count2 = it->second;

        if ((f1 == 1 && count1 == 1) || (f2 == 1 && count2 == 1))
            return true;

        if ((abs(f1 - f2) == 1) && ((f1 > f2 && count1 == 1) || (f2 > f1 && count2 == 1)))
            return true;

        return false;
    }
};
