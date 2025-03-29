/* You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.

Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500 */

class Solution {
  public:
   int findSlot(int slot, vector<int> &parent) {
        if (parent[slot] == slot) return slot;
        return parent[slot] = findSlot(parent[slot], parent); // Path compression
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        // Store jobs as (profit, deadline) pairs
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Sort jobs by profit in descending order
        sort(jobs.rbegin(), jobs.rend());
        
        // Find max deadline to create DSU structure
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> parent(maxDeadline + 1);
        
        // Initialize the DSU parent array (Initially, each slot points to itself)
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        int jobCount = 0, maxProfit = 0;
        
        // Try placing each job
        for (auto &job : jobs) {
            int prof = job.first, dead = job.second;
            
            // Find the latest available slot for this job
            int availableSlot = findSlot(dead, parent);
            
            if (availableSlot > 0) { // If a valid slot exists
                parent[availableSlot] = findSlot(availableSlot - 1, parent); // Update DSU
                jobCount++;
                maxProfit += prof;
            }
        }
        
        return {jobCount, maxProfit};
    }
};
