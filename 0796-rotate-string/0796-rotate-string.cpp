class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size()!=goal.size()) return false;
        goal+=goal;
        for(int i=0;i<s.size();i++)
        {
            if(s==goal.substr(i,s.size()))
            {
                return true;
            }
        }
        return false;
    }
};