class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size()==1) return s;
        if(s.size()==2)
        {
            if(s[0]==s[1]) return s;
            string t="";
            t+=s[0];
            return t;
        }

        int i=0;
        int sz=1;
        string ans="";
        ans+=s[0];
        while(i<s.size())
        {
            int j=i;
            int k=i+1;
            while(j>=0 && k<s.size())
            {
                int size=0;
                if(s[j]==s[k])
                {
                    int temp=k-j+1;
                    if(s.substr(j,temp).size()>ans.size())
                    {
                        ans=s.substr(j,temp);
                    }
                    j--;
                    k++;
                }
                else
                {
                    break;
                }
            }
            j=i-1;
            k=i+1;
            while(j>=0 && k<s.size())
            {
                int size=0;
                if(s[j]==s[k])
                {
                    int temp=k-j+1;
                    if(s.substr(j,temp).size()>ans.size())
                    {
                        ans=s.substr(j,temp);
                    }
                    j--;
                    k++;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};