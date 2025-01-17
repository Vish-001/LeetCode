class Solution {
public:

    bool Palindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void Func(int i,vector<string>ds,string s,vector<vector<string>>&ans)
    {
        if(i==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(Palindrome(s.substr(i,j-i+1)))
            {
                ds.push_back(s.substr(i,j-i+1));
                Func(j+1,ds,s,ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>ds;
        Func(0,ds,s,ans);
        return ans;
    }
};