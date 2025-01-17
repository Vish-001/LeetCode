class Solution {
public:
    void Func(string s,int open,int close,int &n,vector<string>&ans)
    {
        if(open+close==2*n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)
        {
            Func(s+'(',open+1,close,n,ans);
        }
        if(close<open)
        {
            Func(s+')',open,close+1,n,ans);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        Func("",0,0,n,ans);
        return ans;
    }
};