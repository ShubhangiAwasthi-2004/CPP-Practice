 //Dijkstra's Algorithm 

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Because the graph is undirected
        }
        
        // Step 2: Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        // Min-heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int curr_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Visit neighbors
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (curr_dist + weight < dist[v]) {
                    dist[v] = curr_dist + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
        
    }
};
