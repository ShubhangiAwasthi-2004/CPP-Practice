class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> st;

        for (int i = 0; i < color.size(); i++) {
            if (!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
                st.pop(); // remove the matching pair
            } else {
                st.push({color[i], radius[i]});
            }
        }

        return st.size(); // remaining balls
    }
};
