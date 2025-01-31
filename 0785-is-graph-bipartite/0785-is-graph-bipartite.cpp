class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n, -1);
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) 
        {
            if (vis[start] == -1) // Check all components
            {
                queue<pair<int, int>> q;
                q.push({start, 0});
                vis[start] = 1;
                color[start] = 0;

                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    int node = p.first;
                    int col = p.second;

                    for (auto c : graph[node])
                    {
                        if (vis[c] == -1)
                        {
                            vis[c] = 1;
                            color[c] = 1 - col;
                            q.push({c, color[c]});
                        }
                        else if (color[c] == col)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
