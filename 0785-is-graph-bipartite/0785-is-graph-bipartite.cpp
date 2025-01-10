class Solution {
public:
    // BFS function to check bipartiteness for a connected component
    bool BFS(int startNode, vector<int>& col, vector<vector<int>>& graph) {
        queue<pair<int, int>> q;
        q.push({startNode, 1}); // Start with the first node and color it with 1
        col[startNode] = 1;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int node = p.first;
            int clr = p.second;

            for (int neighbor : graph[node]) {
                if (col[neighbor] == -1) {
                    int nclr = 1 - clr; // Flip color
                    col[neighbor] = nclr;
                    q.push({neighbor, nclr});
                } else if (col[neighbor] == clr) {
                    return false; // If a neighbor has the same color, it's not bipartite
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1); // Color array, -1 indicates uncolored

        for (int i = 0; i < n; i++) {
            // Check each component in the graph
            if (col[i] == -1) { // If not colored, start BFS
                if (!BFS(i, col, graph)) {
                    return false; // If any component isn't bipartite, return false
                }
            }
        }
        return true;
    }
};
