//You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively.
//A single person can perform only one activity at a time, meaning no two activities can overlap.
//Your task is to determine the maximum number of activities that a person can complete in a day.

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return a.first < b.first; // Sort in ascending order
}

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int,int>> v;
        for(int i=0; i<start.size(); i++){
            v.push_back(make_pair(finish[i], start[i]));
        }
        sort(v.begin(), v.end(), cmp);
        int deadLine = -1, count = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].second > deadLine){
                deadLine = v[i].first;
                count++;
            }
        }
        return count;
    }
};
