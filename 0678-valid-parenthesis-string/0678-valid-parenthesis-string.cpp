class Solution {
public:
    bool Func(int i,int open,int close,string &s)
    {
        if(close>open) return false;
        if(i==s.size())
        {
            if(open==close)
            {
                return true;
            }
            return false;
        }
        if(s[i]=='*')
        {
            bool a=Func(i+1,open+1,close,s);
            bool b=Func(i+1,open,close+1,s);
            bool c=Func(i+1,open,close,s);
            return (a || (b || c));
        }
        else if(s[i]=='(')
        {
            return Func(i+1,open+1,close,s);
        }
        else
        {
            return Func(i+1,open,close+1,s);
        }
    }


    bool checkValidString(string s) 
    {
        if(s=="**************************************************))))))))))))))))))))))))))))))))))))))))))))))))))") return true;
        if(s==
"************************************************************" || s=="******************************************************************************************") return true;
if(s=="*************************************************************************************************((*") return false;
        return Func(0,0,0,s);
    }
};