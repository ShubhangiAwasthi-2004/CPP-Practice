class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int luckyCount = 0;
        vector<int> addNeeded;

        // Step 1: Count lucky and calculate needed additions for unlucky troops
        for (int soldiers : arr) {
            if (soldiers % k == 0) {
                luckyCount++;
            } else {
                addNeeded.push_back(k - (soldiers % k));
            }
        }

        // Step 2: Required lucky troops
        int required = (n + 1) / 2;  // ceil(n/2)
        if (luckyCount >= required) return 0;

        // Step 3: Sort and sum smallest additions needed
        sort(addNeeded.begin(), addNeeded.end());
        int troopsToFix = required - luckyCount;
        int totalAdded = 0;

        for (int i = 0; i < troopsToFix; i++) {
            totalAdded += addNeeded[i];
        }

        return totalAdded;
    }
};
