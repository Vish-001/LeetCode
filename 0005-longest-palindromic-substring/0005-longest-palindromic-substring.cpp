class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size()==1) return s;
        if(s.size()==2)
        {
            string t="";
            t+=s[0];
            if(s[1]==s[0]) return s;
            return t;
        }
        int ans=1;
        string A="";
        A+=s[0];
        for(int i=0;i<s.size();i++)
        {
            int k=i-1;
            int j=i+1;
            while(k>=0 && j<s.size())
            {
                if(s[k]==s[j])
                {
                    int temp=j-k+1;
                    if(temp>ans)
                    {
                        ans=temp;
                        A=s.substr(k,temp);
                    }
                    k--;
                    j++;
                }
                else
                {
                    break;
                }
            }
            k=i;j=i+1;
            while(k>=0 && j<s.size())
            {
                if(s[k]==s[j])
                {
                    int temp=j-k+1;
                    if(temp>ans)
                    {
                        ans=temp;
                        A=s.substr(k,temp);
                    }
                    k--;
                    j++;
                }
                else
                {
                    break;
                }
            }

        }
        return A;
    }
};