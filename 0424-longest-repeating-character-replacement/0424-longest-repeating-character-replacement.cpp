class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int mf=0;
        int ans=0;
        int l=0;
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>mf)
            {
                mf=mp[s[i]];
            }

            if((i-l+1)-mf<=k)
            {
                ans=max(ans,i-l+1);
            }
            else
            {
                while((i-l+1)-mf>k)
                {
                    if(mp[s[l]]==mf)
                    {
                        mf--;
                        for(auto &p:mp)
                        {
                            mf=max(mf,p.second);
                        }
                    }
                    mp[s[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};