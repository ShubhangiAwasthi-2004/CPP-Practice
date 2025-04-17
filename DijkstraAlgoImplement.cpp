//Implementation of Dijkstra Algorithm.

class Solution {
public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> graph(V);

        // Build adjacency list
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int minCycle = INF;

        // Dijkstra from every node
        for (int start = 0; start < V; ++start) {
            vector<int> dist(V, INF);
            vector<int> parent(V, -1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                for (int i = 0; i < graph[u].size(); ++i) {
                    int v = graph[u][i].first;
                    int w = graph[u][i].second;

                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        parent[v] = u;
                        pq.push({dist[v], v});
                    } else if (parent[u] != v && parent[v] != u) {
                        // Found a cycle
                        minCycle = min(minCycle, dist[u] + dist[v] + w);
                    }
                }
            }
        }

        return (minCycle == INF) ? -1 : minCycle;
    }
};
