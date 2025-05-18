// Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][],
// where each adj[i] represents the list of vertices connected to vertex i. 
// Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to
// right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

// Note: Do traverse in the same order as they are in the given adjacency list.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
     void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
           int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;

        dfsHelper(0, adj, visited, result);

        return result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
