class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        if(s.size()%2!=0) return false;
        int open=0;
        int close=0;

        for(int i=0;i<s.size();i++)
        {
            int j=s.size()-1-i;
            if(s[i]=='(' || locked[i]=='0')
            {
                open++;
            }
            else
            {
                open--;
                if(open<0) return false;
            }

            if(s[j]==')' || locked[j]=='0')
            {
                close++;
            }
            else
            {
                close--;
                if(close<0) return false;
            }
        }
        return true;
    }
};