class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.size()>s.size()) return "";
        int sidx=-1;
        int r=0;
        int l=0;
        int cnt=0;
        int ans=INT_MAX;
        int hash[256]={0};
        for(auto c:t)
        {
            hash[c]++;
        }
        while(r<s.size())
        {
            if(hash[s[r]]>0)
            {
                cnt++;
            }
            hash[s[r]]--;
            r++;
            while(cnt==t.size())
            {
                if(r-l<ans)
                {
                    ans=r-l;
                    sidx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    cnt--;
                }
                l++;
            }
        }
        if(sidx==-1) return "";
        return s.substr(sidx,ans);
    }
};