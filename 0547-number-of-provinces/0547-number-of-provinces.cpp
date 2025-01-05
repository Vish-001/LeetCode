class Solution {
public:
    void BFS(int node,vector<int>&vis,vector<vector<int>>& iC)
    {
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int src=q.front();
            q.pop();
            vis[src]=1;
            for(int i=0;i<iC.size();i++)
            {
                
                if(iC[src-1][i]==1 && vis[i+1]==0)
                {
                    vis[i+1]=1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& iC) 
    {
        int ans=0;
        int n=iC.size();
        vector<int>vis(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                BFS(i,vis,iC);
                ans++;
            }
        }
        return ans;
    }
};