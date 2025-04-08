//Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. 
//Determine whether a specific edge between two vertices (c, d) is a bridge.

//Note:
//An edge is called a bridge if removing it increases the number of connected components of the graph.
//if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.

class Solution {
  public:
      void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V];

        // Step 1: Build the graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Remove the edge (c, d)
        auto removeEdge = [&](int u, int v) {
            adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
            adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
        };
        removeEdge(c, d);

        // Step 3: DFS from node c and check if d is reachable
        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        // Step 4: If d is not visited, edge (c, d) is a bridge
        return !visited[d];
    }
};
