class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int ans=0;
        int last[3]={-1,-1,-1};
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a']=i;
            if(last[0]>=0 && last[1]>=0 && last[2]>=0)
            {
                ans+=min(last[0],min(last[1],last[2]))+1;
            }
        }
        return ans;
    }
};