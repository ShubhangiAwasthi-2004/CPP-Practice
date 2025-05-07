//Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1,
//where each adj[i] represents the list of vertices connected to vertex i.

//Create a clone of the graph, where each node in the graph contains an integer val and
//an array (neighbors) of nodes, containing nodes that are adjacent to the current node

class Solution {
  public:
    // A hash map to store the visited node and its clone
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node was already visited before, return the clone from the map
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new node with the same value as the original
        Node* cloneNode = new Node(node->val);
        // Save this node in the visited map
        visited[node] = cloneNode;

        // Iterate through the neighbors to clone them
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
