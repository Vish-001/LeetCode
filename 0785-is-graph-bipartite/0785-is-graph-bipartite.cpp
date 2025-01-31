class Solution {
public:
    bool DFS(int s, vector<int>& col, vector<vector<int>>& graph) 
    {
        stack<int> st;
        st.push(s);
        col[s] = 0; // Start with color 0

        while (!st.empty()) 
        {
            int node = st.top();
            st.pop();

            for (int neighbor : graph[node]) 
            {
                if (col[neighbor] == -1) 
                {
                    col[neighbor] = 1 - col[node]; // Assign opposite color
                    st.push(neighbor);
                } 
                else if (col[neighbor] == col[node]) 
                {
                    return false; // Same color detected
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> col(n, -1); // Color array, -1 indicates uncolored

        for (int i = 0; i < n; i++) 
        {
            if (col[i] == -1) 
            { 
                if (!DFS(i, col, graph)) 
                {
                    return false; 
                }
            }
        }
        return true;
    }
};
