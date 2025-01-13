class Solution {
public:
    int minimumLength(string s) 
    {
        int ans=0;
        map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
            if(mp[c]>=3)
            {
                mp[c]=1;
            }
        }
        for(auto &p:mp)
        {
            // while(p.second>=3)
            // {
            //     p.second-=2;
            // }
            ans+=p.second;
        }
        return ans;
    }
};