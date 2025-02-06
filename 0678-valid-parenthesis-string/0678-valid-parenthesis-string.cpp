class Solution {
public:
    bool checkValidString(string s) 
    {
        int mini=0;
        int maxi=0;
        for(auto c:s)
        {
            if(c=='(')
            {
                mini++;
                maxi++;
            }
            else if(c==')')
            {
                mini--;
                maxi--;
            }
            else
            {
                maxi++;
                mini--;
            }
            if(mini<0)
            {
                mini=0;
            }
            if(maxi<0) return false;
        }
        if(maxi==0 || mini==0) return true;
        return false;
    }
};