class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int open=0;
        int close=0;
        string ans="";
        for(auto c:s)
        {
            if(open==0 && c=='(')
            {
                open++;
            }
            else if(c=='(')
            {
                open++;
                ans+='(';
            }
            else if(open>1)
            {
                open--;
                ans+=')';
            }
            else
            {
                open--;
            }
        }
        return ans;
    }
};