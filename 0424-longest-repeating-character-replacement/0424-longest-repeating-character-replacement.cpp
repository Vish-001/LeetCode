class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int ans=0;
        int max_freq=0;
        unordered_map<char,int>mp;
        int l=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            max_freq=max(max_freq,mp[s[i]]);
            if((i-l+1)-max_freq>k)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                {
                    mp.erase(mp[s[l]]);
                }
                l++;
            }
            for(auto& p:mp)
            {
                max_freq=max(max_freq,p.second);
            }

            ans=max(ans,i-l+1);
        }
        return ans;
    }
};