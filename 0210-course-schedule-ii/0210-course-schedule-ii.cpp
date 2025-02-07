class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) 
    {
        vis[node] = 1; // Mark node as "visiting"

        for (auto c : adj[node]) 
        {
            if (vis[c] == 0)  // If not visited, do DFS
            {
                if (dfs(c, vis, adj, st)) 
                {
                    return true; // Cycle detected
                }
            }
            else if (vis[c] == 1) // Back edge found, cycle detected
            {
                return true;
            }
        }

        vis[node] = 2; // ✅ Mark node as "fully processed"
        st.push(node); // Push to stack for topological order
        return false;
    }

    vector<int> findOrder(int num, vector<vector<int>>& pre) 
    {
        vector<int> ans;
        vector<vector<int>> adj(num);
        
        // Build adjacency list
        for (auto& p : pre) 
        {
            int v = p[0], u = p[1];
            adj[u].push_back(v);
        }

        vector<int> vis(num, 0);
        stack<int> st;
        
        // Perform DFS on each unvisited node
        for (int i = 0; i < num; i++) 
        {
            if (vis[i] == 0) 
            {
                if (dfs(i, vis, adj, st)) // If cycle detected, return empty list
                {
                    return {};
                }
            }
        }

        while (!st.empty()) 
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
