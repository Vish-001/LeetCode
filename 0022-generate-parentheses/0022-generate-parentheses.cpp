class Solution {
public:
    void Func(int open,int close,int n,string ds,vector<string>&ans)
    {
        if(open+close==2*n)
        {
            ans.push_back(ds);
            return;
        }

        if(open<n)
        {
            Func(open+1,close,n,ds+'(',ans);
        }
        if(close<open)
        {
            Func(open,close+1,n,ds+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        Func(0,0,n,"",ans);
        return ans;
    }
};