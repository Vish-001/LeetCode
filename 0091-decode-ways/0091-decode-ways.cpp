class Solution {
public:
    int ans;
    void Func(int i,string s)
    {
        if(i==s.size())
        {
            ans++;
            return;
        }
        if(i>s.size()) return;
        if(s[i]=='0')
        {
            return;
        }
        if(i<s.size()-1)
        {
            string str="";
            str+=s[i];
            str+=s[i+1];
            if(str<="26")
            {
                Func(i+2,s);
            }
        }
        Func(i+1,s);
        
    }
    int numDecodings(string s) 
    {
        ans=0;
        Func(0,s);
        if(s[0]=='0') return 0;
        return ans;
    }
};