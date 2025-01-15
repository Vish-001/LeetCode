class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        int st=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') continue;
            int ws=st;
            while(s[i]!=' ' && i<s.size())
            {
                s[st]=s[i];
                st++;
                i++;
            }
            reverse(s.begin()+ws,s.begin()+st);

            if(i<s.size()) s[st++]=' ';
        }
        if(s[s.size()-1]==' ') st--;
        s.resize(st);
        return s;
    }
};