class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int rotn=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)
                {
                    rotn++;
                }
            }
        }
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        int time=0;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int row=p.first.first;
            int col=p.first.second;
            int t=p.second;
            time=t;
            for(int i=0;i<4;i++)
            {
                int nr=dr[i]+row;
                int nc=dc[i]+col;
                if(nc>=0 && nr>=0 && nr<m && nc<n && grid[nr][nc]==1)
                {
                    rotn--;
                    grid[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        if(rotn>0) return -1;
        return time;
    }
};