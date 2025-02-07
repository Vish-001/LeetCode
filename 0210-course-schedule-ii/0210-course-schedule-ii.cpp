class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) 
    {
        vector<int> ans;
        vector<vector<int>> adj(num);
        for (int i = 0; i < pre.size(); i++) 
        {
            int v = pre[i][0];
            int u = pre[i][1];

            adj[u].push_back(v);
        }

        vector<int> vis(num, 0);
        vector<int>indegree(num,0);

        for(int i=0;i<num;i++)
        {
            for(auto c:adj[i])
            {
                indegree[c]++;
            }
        }
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto c:adj[node])
            {
                indegree[c]--;
                if(indegree[c]==0)
                {
                    q.push(c);
                }
            }
        }

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]>0) return{};
        }
        return ans;
    }
};