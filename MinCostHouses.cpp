//Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the location of each house,
//the task is to find the minimum cost to connect all the houses of the city.

//The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj)
//i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.

#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Find the node not in MST with the smallest cost
            for (int j = 0; j < n; ++j) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            inMST[u] = true;
            totalCost += minDist[u];

            // Update distances for remaining nodes
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};
