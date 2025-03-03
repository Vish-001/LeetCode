class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>mp;
        for(auto c:tasks)
        {
            mp[c]++;
        }
        priority_queue<int>pq;

        for(auto& p:mp)
        {
            pq.push(p.second);
        }

        int ans=0;
        
        while(!pq.empty())
        {
            vector<int>temp;
            int cnt=0;
            for(int i=0;i<=n;i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    cnt++;
                    temp.push_back(freq);
                }
            }

            for(auto c:temp)
            {
                if(c>0)
                {
                    pq.push(c);
                }
            }

            if(!pq.empty())
            {
                ans+=n+1;
            }
            else
            {
                ans+=cnt;
            }
        }

        return ans;
    }
};