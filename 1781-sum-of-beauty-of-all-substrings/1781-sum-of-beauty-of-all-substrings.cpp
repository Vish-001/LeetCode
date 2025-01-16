class Solution {
public:
    int beautySum(string s) 
    {
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                mp[s[j]]++;
                int mini=s.size();
                int maxi=0;
                for(auto&p:mp)
                {
                    mini=min(mini,p.second);
                    maxi=max(maxi,p.second);
                }
                ans+=maxi-mini;
            }
            mp.clear();
        }
        return ans;
    }
};