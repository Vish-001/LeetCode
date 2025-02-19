class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s==t) return true;
        if(s.size()!=t.size()) return false;

        map<char,char>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                for(auto& p:mp)
                {
                    if(p.second==t[i])
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(t[i]!=mp[s[i]])
                {
                    return false;
                }
            }
            mp[s[i]]=t[i];
        }

        return true;
    }
};