class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int> vis(graph.size(), -1);
        vector<int> color(graph.size(), -1);
        queue<pair<int, int>> q;
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==1) continue;
            q.push({i, 0}); 
            vis[i] = 1;
            color[i] = 0;

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
        return true;
    }
};
