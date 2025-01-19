class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int mf=0;
        int ans=0;
        while(r<s.size())
        {
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            if(((r-l+1)-mf) > k)
            {
                mp[s[l]]--;
                l++;
            }
            else
            {
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};