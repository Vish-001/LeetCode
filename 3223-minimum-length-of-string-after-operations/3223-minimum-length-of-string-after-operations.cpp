class Solution {
public:
    int minimumLength(string s) 
    {
        int ans=0;
        map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        for(auto &p:mp)
        {
            while(p.second>=3)
            {
                p.second-=2;
            }
            ans+=p.second;
        }
        return ans;
    }
};