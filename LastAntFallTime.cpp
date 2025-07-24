class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
          int maxTime = 0;

        // Ants going left fall off in time = position
        for (int pos : left) {
            maxTime = max(maxTime, pos);
        }

        // Ants going right fall off in time = n - position
        for (int pos : right) {
            maxTime = max(maxTime, n - pos);
        }

        return maxTime;
    }
};
